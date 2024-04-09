// 输出
// 9 3 15 20 7
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVec(vector<int> &ivec)
{
    for (auto &elem : ivec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

class Solution
{
private:
    void traversal(TreeNode *node, vector<int> &ivec)
    {
        if (node == nullptr)
        {
            return;
        }
        //
        traversal(node->left, ivec);
        ivec.push_back(node->val);
        traversal(node->right, ivec);
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }

        // 后序序列最后一个元素
        int nodeVal = postorder[postorder.size() - 1];
        // 后序序列最后一个元素在中序序列的位置
        int index;
        for (index = 0; index < inorder.size(); index++)
        {
            if (inorder[index] == nodeVal)
            {
                break;
            }
        }

        // 创建节点
        TreeNode *node = new TreeNode(nodeVal);

        // 切中序
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + index);
        vector<int> inorderRight(inorder.begin() + index + 1, inorder.end());

        // 舍弃后序序列最后一个元素
        postorder.resize(postorder.size() - 1);

        // 切后序
        vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end());

        node->left = buildTree(inorderLeft, postorderLeft);
        node->right = buildTree(inorderRight, postorderRight);

        return node;
    }

    //
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    //
    void freeMemory(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
};

int main()
{
    vector<int> result;

    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.buildTree(inorder, postorder);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    solution.freeMemory(newRoot);

    return 0;
}
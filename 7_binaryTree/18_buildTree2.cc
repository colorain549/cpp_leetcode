// 从前序序列和中序序列构造二叉树
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
public:
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
    //
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 && inorder.size() == 0)
        {
            return nullptr;
        }
        // 前序序列的第一个元素为根节点
        int nodeVal = preorder[0];
        // 中序序列中找切割点
        int index = 0;
        for (index = 0; index < inorder.size(); index++)
        {
            if (nodeVal == inorder[index])
            {
                break;
            }
        }
        // 创建根节点
        TreeNode *node = new TreeNode(nodeVal);
        // 切中序
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + index);
        vector<int> inorderRight(inorder.begin() + index + 1, inorder.end());
        // 切前序
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + inorderLeft.size());
        vector<int> preorderRight(preorder.begin() + 1 + inorderLeft.size(), preorder.end());

        node->left = buildTree(preorderLeft, inorderLeft);
        node->right = buildTree(preorderRight, inorderRight);

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

    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.buildTree(preorder, inorder);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    solution.freeMemory(newRoot);

    return 0;
}
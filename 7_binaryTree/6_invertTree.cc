// 输出
// 2 3 1
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
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
    void inOrderTraversal(TreeNode *node, vector<int> &ivec)
    {
        if (node == nullptr)
        {
            return;
        }
        // 中序遍历
        inOrderTraversal(node->left, ivec);
        ivec.push_back(node->val);
        inOrderTraversal(node->right, ivec);
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 根节点空
        if (root == nullptr)
        {
            return nullptr;
        }

        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }

    vector<int> getSeq(TreeNode *root)
    {
        vector<int> result;
        inOrderTraversal(root, result);
        return result;
    }
};

int main()
{
    vector<int> result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->right = sec;
    sec->left = third;

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.invertTree(root);

    result = solution.getSeq(newRoot);
    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
// 输出
// true
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
    bool traversal(TreeNode *node, int count)
    {
        // 叶子节点 && count = 0
        if (node->left == nullptr && node->right == nullptr && count == 0)
        {
            return true;
        }

        // 叶子节点 && count != 0
        if (node->left == nullptr && node->right == nullptr && count != 0)
        {
            return false;
        }

        if (node->left)
        {
            count -= node->left->val;
            if (traversal(node->left, count))
            {
                return true;
            }
            count += node->left->val;
        }

        if (node->right)
        {
            count -= node->right->val;
            if (traversal(node->right, count))
            {
                return true;
            }
            count += node->right->val;
        }

        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        return traversal(root, targetSum - root->val);
    }
};

int main()
{
    bool result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->right = sec;
    sec->left = third;

    //
    // 解决方案
    //
    int targetSum = 6;
    Solution solution;
    result = solution.hasPathSum(root, targetSum);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
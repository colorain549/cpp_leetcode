// 输出
// 3
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
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
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftDepth = getHeight(node->left);
        int rightDepth = getHeight(node->right);
        int result = max(leftDepth, rightDepth) + 1;
        return result;
    }

public:
    int maxDepth(TreeNode *root)
    {
        // 二叉树的高度为最大深度
        return getHeight(root);
    }
};

int main()
{
    int result;

    TreeNode *root = new TreeNode(3);
    TreeNode *sec = new TreeNode(9);
    TreeNode *third = new TreeNode(20);
    TreeNode *fourth = new TreeNode(15);
    TreeNode *fifth = new TreeNode(7);

    root->left = sec;
    root->right = third;
    third->left = fourth;
    third->right = fifth;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.maxDepth(root);

    cout << result << endl;

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
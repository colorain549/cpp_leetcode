// 输出
// 24
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int subleft = sumOfLeftLeaves(root->left);
        // 左叶子的定义
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            subleft = root->left->val;
        }
        int subright = sumOfLeftLeaves(root->right);
        int result = subleft + subright;

        return result;
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
    result = solution.sumOfLeftLeaves(root);

    cout << result << endl;

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
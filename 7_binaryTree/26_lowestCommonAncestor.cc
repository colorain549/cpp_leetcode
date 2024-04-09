// 输出
// 2
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *subleft = lowestCommonAncestor(root->left, p, q);
        TreeNode *subright = lowestCommonAncestor(root->right, p, q);

        if (subleft != nullptr && subright != nullptr)
        {
            return root;
        }
        else if (subleft == nullptr && subright != nullptr)
        {
            return subright;
        }
        else if (subleft != nullptr && subright == nullptr)
        {
            return subleft;
        }
        else
        {
            return nullptr;
        }

        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->right = sec;
    sec->left = third;

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *node = solution.lowestCommonAncestor(root, sec, third);

    cout << node->val << endl;

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
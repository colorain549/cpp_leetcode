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
private:
    bool traversal(TreeNode *subleft, TreeNode *subright)
    {
        // 左空右空
        if (subleft == nullptr && subright == nullptr)
        {
            return true;
        }
        // 左空右不空
        else if (subleft == nullptr && subright != nullptr)
        {
            return false;
        }
        // 左不空右空
        else if (subleft != nullptr && subright == nullptr)
        {
            return false;
        }
        // 左不空右不空且值不等
        else if (subleft->val != subright->val)
        {
            return false;
        }
        // 左不空右不空且值相等
        else
        {
            bool outside = traversal(subleft->left, subright->right);
            bool inside = traversal(subleft->right, subright->left);
            bool result = outside && inside;
            return result;
        }
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        return traversal(root->left, root->right);
    }
};

int main()
{
    bool result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(2);

    root->left = sec;
    root->right = third;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.isSymmetric(root);

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
// 输出
// true
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
private:
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        // 左子树
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
        {
            return -1;
        }

        // 右子树
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
        {
            return -1;
        }

        // 左子树右子树绝对差
        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(leftHeight, rightHeight);
        }
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // 返回-1则不是平衡二叉树
        if (getHeight(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    bool result;

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
    result = solution.isBalanced(root);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
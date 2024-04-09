// 输出
// 2
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::min;
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
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (node->left == nullptr && node->right != nullptr)
        {
            return rightHeight + 1;
        }
        if (node->left != nullptr && node->right == nullptr)
        {
            return leftHeight + 1;
        }
        int result = min(leftHeight, rightHeight) + 1;
        return result;
    }

public:
    int minDepth(TreeNode *root)
    {
        // 二叉树的高度为最大深度
        // 最小深度是根到最近的叶子节点
        // 左子树空右子树不空则最小深度为右子树的深度+1
        // 左子树不空右子树空则最小深度为左子树的深度+1
        // 左右子树都不为空则为左右子树深度最小值+1
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
    result = solution.minDepth(root);

    cout << result << endl;

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
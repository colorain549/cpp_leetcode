// 输出
// 3
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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int countLeftNodes = countNodes(root->left);
        int countRightNodes = countNodes(root->right);
        int result = countLeftNodes + countRightNodes + 1;

        return result;
    }
};

int main()
{
    int result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->right = sec;
    sec->left = third;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.countNodes(root);

    cout << result << endl;

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
// 输出
// 1 2 3
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
    void traversal(TreeNode *node, vector<int> &ivec)
    {
        if (node == nullptr)
        {
            return;
        }
        // 前序遍历(中左右)
        ivec.push_back(node->val);
        traversal(node->left, ivec);
        traversal(node->right, ivec);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
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
    result = solution.preorderTraversal(root);

    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
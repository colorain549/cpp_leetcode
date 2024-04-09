// 输出
// 1 3 2 6
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
    void traversal(TreeNode *node, vector<int> &ivec)
    {
        if (node == nullptr)
        {
            return;
        }
        traversal(node->left, ivec);
        ivec.push_back(node->val);
        traversal(node->right, ivec);
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }

        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    vector<int> inorderTrversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void freeMemory(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
};

int main()
{
    vector<int> result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->left = sec;
    root->right = third;

    //
    // 解决方案
    //
    int val = 6;
    Solution solution;
    TreeNode *newRoot = solution.insertIntoBST(root, val);

    result = solution.inorderTrversal(newRoot);
    printVec(result);

    // 释放内存
    solution.freeMemory(newRoot);

    return 0;
}
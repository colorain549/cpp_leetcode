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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == val)
        {
            return root;
        }

        if (root->val > val)
        {
            return searchBST(root->left, val);
        }

        if (root->val < val)
        {
            return searchBST(root->right, val);
        }

        return root;
    }

    vector<int> inorderTrversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main()
{
    vector<int> result;

    TreeNode *root = new TreeNode(4);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(7);
    TreeNode *fourth = new TreeNode(1);
    TreeNode *fifth = new TreeNode(3);

    root->left = sec;
    root->right = third;
    sec->left = fourth;
    sec->right = fifth;

    //
    // 解决方案
    //
    int val = 2;
    Solution solution;
    TreeNode *newRoot = solution.searchBST(root, val);

    result = solution.inorderTrversal(newRoot);
    printVec(result);

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
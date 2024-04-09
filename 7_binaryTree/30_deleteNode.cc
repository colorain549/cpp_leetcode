// 输出
// 1 3
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                return root->right;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                return root->left;
            }
            else
            {
                TreeNode *cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right;
            }
        }

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

    vector<int> inorderTraversal(TreeNode *root)
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
    int val = 2;
    Solution solution;
    TreeNode *newRoot = solution.deleteNode(root, val);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
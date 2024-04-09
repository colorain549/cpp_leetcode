// 输出
// 26 21 15 8
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

private:
    int pre = 0;
    void traversalConvert(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return;
        }

        traversalConvert(cur->right);

        cur->val += pre;
        pre = cur->val;

        traversalConvert(cur->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        traversalConvert(root);
        return root;
    }

    vector<int> inorderTraversal(TreeNode *node)
    {
        vector<int> result;
        traversal(node, result);
        return result;
    }
};

int main()
{
    vector<int> result;

    TreeNode *root = new TreeNode(6);
    TreeNode *sec = new TreeNode(5);
    TreeNode *third = new TreeNode(7);
    TreeNode *fourth = new TreeNode(8);

    root->left = sec;
    root->right = third;
    third->right = fourth;

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.convertBST(root);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
// 输出
// 9 3 8
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // !!!若root1空,则返回root2!!!
        if (root1 == nullptr)
        {
            return root2;
        }

        if (root2 == nullptr)
        {
            return root1;
        }

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
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

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(3);

    root->right = sec;
    sec->left = third;

    TreeNode *root2 = new TreeNode(8);
    TreeNode *third2 = new TreeNode(6);
    root2->right = third2;

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.mergeTrees(root, root2);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;
    
    delete third2;
    delete root2;

    return 0;
}
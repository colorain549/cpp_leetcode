// 输出
// 1 2
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // 该节点比区间的左端点小
        if (root->val < low)
        {
            // 向右寻找是否有符合条件的节点
            return trimBST(root->left, low, high);
        }

        // 该节点比区间的左端点大
        if (root->val > high)
        {
            // 向左寻找是否有符合条件的节点
            return trimBST(root->right, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

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
    int low = 0;
    int high = 2;
    Solution solution;
    TreeNode *newRoot = solution.trimBST(root, low, high);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
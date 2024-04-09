// 输出
// 1
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
    int maxDepth = INT32_MIN;
    int result = 0;
    void traversal(TreeNode *node, int depth)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = node->val;
            }
        }

        if (node->left)
        {
            depth++;
            traversal(node->left, depth);
            // 回溯
            depth--;
        }

        if (node->right)
        {
            depth++;
            traversal(node->right, depth);
            depth--;
        }
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 0);
        return result;
    }
};

int main()
{
    int result;

    TreeNode *root = new TreeNode(2);
    TreeNode *sec = new TreeNode(1);
    TreeNode *third = new TreeNode(3);

    root->left = sec;
    root->right = third;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.findBottomLeftValue(root);

    cout << result << endl;

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
// P.S !!!记得回溯!!!
// 输出
// 3 2 1 6 0 5
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        // !!!看清题目, 理清思路!!!
        if (nums.size() == 0)
        {
            return nullptr;
        }

        int maxVal = INT32_MIN;
        int maxValIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxValIndex = i;
            }
        }

        TreeNode *node = new TreeNode(maxVal);

        vector<int> subleft(nums.begin(), nums.begin() + maxValIndex);
        vector<int> subright(nums.begin() + maxValIndex + 1, nums.end());

        node->left = constructMaximumBinaryTree(subleft);
        node->right = constructMaximumBinaryTree(subright);

        return node;
    }

    vector<int> inorderTraversal(TreeNode *root)
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

    vector<int> nums{3, 2, 1, 6, 0, 5};

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newRoot = solution.constructMaximumBinaryTree(nums);

    result = solution.inorderTraversal(newRoot);
    printVec(result);

    // 释放内存
    solution.freeMemory(newRoot);

    return 0;
}
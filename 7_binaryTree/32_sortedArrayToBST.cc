// 输出
// -10 -3 0 5 9
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

    TreeNode *traversalConvert(vector<int> &nums, int low, int high)
    {
        // 注意终止条件
        if (low > high)
        {
            return nullptr;
        }

        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(nums[mid]);

        node->left = traversalConvert(nums, low, mid - 1);
        node->right = traversalConvert(nums, mid + 1, high);

        return node;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return traversalConvert(nums, 0, nums.size() - 1);
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

// 方案二(已通过):
// class Solution
// {
// public:
//     TreeNode *sortedArrayToBST(vector<int> &nums)
//     {
//         if (nums.size() == 0)
//         {
//             return 0;
//         }

//         int mid = nums.size() / 2;
//         TreeNode *node = new TreeNode(nums[mid]);

//         vector<int> subleft(nums.begin(), nums.begin() + mid);
//         vector<int> subright(nums.begin() + mid + 1, nums.end());

//         node->left = sortedArrayToBST(subleft);
//         node->right = sortedArrayToBST(subright);

//         return node;
//     }
// };

int main()
{
    vector<int> result;

    vector<int> nums{-10, -3, 0, 5, 9};

    //
    // 解决方案
    //
    Solution solution;
    TreeNode *newNode = solution.sortedArrayToBST(nums);

    result = solution.inorderTraversal(newNode);
    printVec(result);

    // 释放内存
    solution.freeMemory(newNode);

    return 0;
}
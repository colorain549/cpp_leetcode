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
    void traversal(TreeNode *node, vector<int> &ivec)
    {
        if (node == nullptr)
        {
            return;
        }
        // 中序遍历
        traversal(node->left, ivec);
        ivec.push_back(node->val);
        traversal(node->right, ivec);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        // 中序遍历
        vector<int> ivec;
        traversal(root, ivec);

        // 比较
        int minVal = INT32_MAX;
        for (int i = 1; i < ivec.size() - 1; i++)
        {
            int diff = ivec[i] - ivec[i - 1];
            if (diff < minVal)
            {
                minVal = diff;
            }
        }

        return minVal;
    }
};

int main()
{
    int result;

    TreeNode *root = new TreeNode(4);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(6);
    TreeNode *fourth = new TreeNode(1);
    TreeNode *fifth = new TreeNode(3);

    root->left = sec;
    root->right = third;
    sec->left = fourth;
    sec->right = fifth;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.getMinimumDifference(root);

    cout << result << endl;

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
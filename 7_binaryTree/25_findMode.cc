// 输出
// 2
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
    //
    int count = 0;
    //
    int maxCount = 0;
    // 初始化
    TreeNode *pre = nullptr;
    //
    vector<int> result;

    void traversal(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return;
        }

        if (pre == nullptr)
        {
            count = 0;
        }
        else if (cur->val == pre->val)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        pre = cur;

        if (count == maxCount)
        {
            result.push_back(cur->val);
        }

        if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        traversal(cur->left);
        traversal(cur->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        result.clear();
        pre = nullptr;

        traversal(root);
        return result;
    }
};

int main()
{
    vector<int> result;

    TreeNode *root = new TreeNode(1);
    TreeNode *sec = new TreeNode(2);
    TreeNode *third = new TreeNode(2);

    root->right = sec;
    sec->left = third;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.findMode(root);

    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
// 输出
// true
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
    bool isValidBST(TreeNode *root)
    {
        // 中序遍历
        vector<int> ivec;
        traversal(root, ivec);

        // 比较
        for (int i = 0; i < ivec.size() - 1; i++)
        {
            if (ivec[i] > ivec[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    bool result;

    TreeNode *root = new TreeNode(2);
    TreeNode *sec = new TreeNode(1);
    TreeNode *third = new TreeNode(3);

    root->left = sec;
    root->right = third;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.isValidBST(root);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
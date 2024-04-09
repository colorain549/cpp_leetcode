// 输出
// 3 2 1
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::reverse;
using std::stack;
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
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // 保存临时节点的栈
        stack<TreeNode *> st;
        // 保存结果的容器
        vector<int> result;
        // 若根节点空
        if (root == nullptr)
        {
            return result;
        }
        // 将根结点入栈
        st.push(root);
        // 当栈非空
        while (!st.empty())
        {
            // 取栈顶节点
            TreeNode *cur = st.top();
            // 保存当前结果
            result.push_back(cur->val);
            // 出栈
            st.pop();
            // 栈先进后出(左右)
            if (cur->left)
            {
                st.push(cur->left);
            }
            if (cur->right)
            {
                st.push(cur->right);
            }
        }
        // 反转数组
        reverse(result.begin(), result.end());
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
    Solution solution;
    result = solution.postorderTraversal(root);

    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
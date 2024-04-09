// 输出
// 1 3 2
#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 保存临时节点的栈
        stack<TreeNode *> st;
        // 保存结果的容器
        vector<int> result;
        TreeNode *cur = root;
        // 若栈非空或cur!=nullptr
        while (!st.empty() || cur != nullptr)
        {
            // 若当前节点存在
            if (cur)
            {
                // 将当前节点入栈
                st.push(cur);
                // 左
                cur = cur->left;
            }
            else
            {
                // 取栈顶节点
                cur = st.top();
                // 保存当前结果
                result.push_back(cur->val);
                // 出栈
                st.pop();
                // 右
                cur = cur->right;
            }
        }
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
    result = solution.inorderTraversal(root);

    printVec(result);

    // 释放内存
    delete third;
    delete sec;
    delete root;

    return 0;
}
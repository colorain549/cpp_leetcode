#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::reverse;
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

void printVec(vector<vector<int>> &ivec)
{
    for (auto &linearArr : ivec)
    {
        for (auto &elem : linearArr)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // 保存临时节点的队列
        queue<TreeNode *> que;
        // 保存最终结果
        vector<vector<int>> result;
        // 根节点存在则入队
        if (root)
        {
            que.push(root);
        }
        // 队列非空
        while (!que.empty())
        {
            int size = que.size();
            vector<int> linearArr;
            for (int i = 0; i < size; i++)
            {
                // 取队头节点
                TreeNode *cur = que.front();
                // 保存当前结果
                linearArr.push_back(cur->val);
                // 出队
                que.pop();
                // 左
                if (cur->left)
                {
                    que.push(cur->left);
                }
                // 右
                if (cur->right)
                {
                    que.push(cur->right);
                }
            }
            result.push_back(linearArr);
        }
        // !!!反转数组!!!
        reverse(result.begin(), result.end());
        return result;
    }
};
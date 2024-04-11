#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
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
    vector<int> largestValues(TreeNode *root)
    {
        // 保存临时节点的队列
        queue<TreeNode *> que;
        // 保存结果的容器
        vector<int> result;
        // 若根节点非空则入队
        if (root)
        {
            que.push(root);
        }
        // 若队列非空
        while (!que.empty())
        {
            // 该层元素数量
            int size = que.size();
            // 当前最大值
            int maxVal = INT32_MIN;
            for (int i = 0; i < size; i++)
            {
                // 取队首节点
                TreeNode *cur = que.front();
                // !!!比较!!!
                if (cur->val > maxVal)
                {
                    maxVal = cur->val;
                }
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
            result.push_back(maxVal);
        }
        return result;
    }
};
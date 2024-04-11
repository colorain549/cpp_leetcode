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
    int minDepth(TreeNode *root)
    {
        // 保存临时节点的队列
        queue<TreeNode *> que;
        // 保存结果
        int depth = 0;
        // 若根节点存在则入队
        if (root)
        {
            que.push(root);
        }
        // 若队列非空
        while (!que.empty())
        {
            int size = que.size();
            // !!!深度!!!
            depth++;
            for (int i = 0; i < size; i++)
            {
                // 取队首节点
                TreeNode *cur = que.front();
                // 出栈
                que.pop();
                if (cur->left)
                {
                    que.push(cur->left);
                }
                if (cur->right)
                {
                    que.push(cur->right);
                }
                // !!!遇到叶子节点则返回!!!
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    return depth;
                }
            }
        }
        return depth;
    }
};
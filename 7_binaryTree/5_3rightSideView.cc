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
    vector<int> rightSideView(TreeNode *root)
    {
        // 保存临时节点的队列
        queue<TreeNode *> que;
        // 保存结果
        vector<int> result;
        // 若根节点存在则入队
        if (root)
        {
            que.push(root);
        }
        // 若队列非空
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                // 取队头节点
                TreeNode *cur = que.front();
                // !!!保存结果(该层最后一个元素)!!!
                if (i == size - 1)
                {
                    result.push_back(cur->val);
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
        }
        return result;
    }
};
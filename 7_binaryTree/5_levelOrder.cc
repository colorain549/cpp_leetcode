// 输出
// [3] [9 20] [15 7]
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 保存临时节点的队列
        queue<TreeNode *> que;
        // 保存最终结果的容器
        vector<vector<int>> result;
        // 检查根节点
        if (root)
        {
            que.push(root);
        }
        // 若队列非空
        while (!que.empty())
        {
            // 当前行元素的数量
            int size = que.size();
            // 保存当前行的元素
            vector<int> linearArr;
            for (int i = 0; i < size; i++)
            {
                // 取队首节点
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
        return result;
    }
};

int main()
{
    vector<vector<int>> result;

    TreeNode *root = new TreeNode(3);
    TreeNode *sec = new TreeNode(9);
    TreeNode *third = new TreeNode(20);
    TreeNode *fourth = new TreeNode(15);
    TreeNode *fifth = new TreeNode(7);

    root->left = sec;
    root->right = third;
    third->left = fourth;
    third->right = fifth;

    //
    // 解决方案
    //
    Solution solution;
    result = solution.levelOrder(root);

    printVec(result);

    // 释放内存
    delete fifth;
    delete fourth;
    delete third;
    delete sec;
    delete root;

    return 0;
}
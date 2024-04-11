// N叉树的层序遍历
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Node
{
public:
    int val;
    vector<Node *> children;
    Node(int x) : val(x), children() {}
};

void printVec(vector<vector<int>> &ivec)
{
    for (const auto &vec : ivec)
    {
        for (int val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // 保存临时节点的队列
        queue<Node *> que;
        // 保存结果容器
        vector<vector<int>> result;
        // 若根节点存在则入队
        if (root)
        {
            que.push(root);
        }
        // 当队列非空
        while (!que.empty())
        {
            int size = que.size();
            vector<int> linearArr;
            for (int i = 0; i < size; i++)
            {
                // 取队首元素(第一层的话是根节点)
                Node *cur = que.front();
                linearArr.push_back(cur->val);
                que.pop();
                // !!!遍历下一层!!!
                for (int i = 0; i < cur->children.size(); i++)
                {
                    if (cur->children[i])
                    {
                        que.push(cur->children[i]);
                    }
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

    Node *root = new Node(1);

    Node *secLeft = new Node(3);
    Node *secMid = new Node(2);
    Node *secRight = new Node(4);

    Node *thirdLeft = new Node(5);
    Node *thirdRight = new Node(6);

    root->children.push_back(secLeft);
    root->children.push_back(secMid);
    root->children.push_back(secRight);

    root->children[0]->children.push_back(thirdLeft);
    root->children[0]->children.push_back(thirdRight);

    //
    // 解决方案
    //
    Solution solution;
    result = solution.levelOrder(root);

    printVec(result);

    // 释放动态分配的节点
    for (Node *node : root->children)
    {
        delete node;
    }
    delete root;

    return 0;
}
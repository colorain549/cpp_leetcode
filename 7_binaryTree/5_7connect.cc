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
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
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
    Node *connect(Node *root)
    {
        // 保存临时节点的队列
        queue<Node *> que;
        // 若根节点存在则入队
        if (root)
        {
            que.push(root);
        }
        // 队列非空
        while (!que.empty())
        {
            int size = que.size();
            Node *nodePre;
            Node *node;
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    // 每层的第一个节点
                    nodePre = que.front();
                    que.pop();
                    // 该层最后一个元素指向下一层的第一个元素
                    node = nodePre;
                }
                else
                {
                    // 假设是第二层的第二个节点
                    node = que.front();
                    que.pop();
                    // 第一个节点指向第二个节点
                    // 该层最后一个元素指向下一层的第一个元素
                    nodePre->next = node;
                    // 更新nodePre
                    nodePre = nodePre->next;
                }
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            nodePre->next = NULL;
        }
        return root;
    }
};
// 输入
// [7][1 2 6 3 4 5 6][6]
// 输出
// [1 2 3 4 5]
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printVec(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 哑节点
        ListNode *dummyNode = new ListNode(0);
        ListNode *cur = dummyNode;
        // 将哑节点加入链表
        dummyNode->next = head;
        while (cur->next)
        {
            // 找到移除链表的元素
            if (cur->next->val == val)
            {
                // 保存要删除的元素
                ListNode *tmp = cur->next;
                // 移除链表元素
                cur->next = cur->next->next;
                // 释放内存
                delete tmp;
            }
            else
            {
                // 检查下一个元素
                cur = cur->next;
            }
        }
        // 保存要返回的节点
        ListNode *ret = dummyNode->next;
        // 释放内存
        delete dummyNode;
        return ret;
    }
};

int main()
{
    // 链表长度
    int length;
    cin >> length;

    // 链表元素
    int item;

    // 创建哑节点
    ListNode *dummyNode = new ListNode(0);
    ListNode *cur = dummyNode;

    // 构建链表
    for (int i = 0; i < length; i++)
    {
        cin >> item;
        ListNode *newNode = new ListNode(item);
        cur->next = newNode;
        cur = cur->next;
    }

    //
    // 解决方案
    int val;
    cin >> val;
    Solution solution;
    solution.removeElements(dummyNode->next, val);

    // 打印链表
    printVec(dummyNode->next);

    // 释放内存
    cur = dummyNode;
    while (cur->next)
    {
        ListNode *tmp = cur->next;
        cur = cur->next;
        delete tmp;
    }
    delete dummyNode;

    return 0;
}
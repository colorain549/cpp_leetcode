// 输入
// [5][2 6 2 1 3]
// 输出
// 2 6 2 1 3
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

void printList(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

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
    //

    // 打印链表
    printList(dummyNode->next);

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
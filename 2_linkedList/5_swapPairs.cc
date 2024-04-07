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

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0);
        ListNode *cur = dummyNode;
        dummyNode->next = head;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            // 保存临时节点
            ListNode *tmp = cur->next;
            ListNode *tmp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmp1;

            // 更新cur
            cur = cur->next->next;
        }
        // 保存返回的节点
        ListNode *ret = dummyNode->next;
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
    //
    Solution solution;
    dummyNode->next = solution.swapPairs(dummyNode->next);

    // 打印链表
    printList(dummyNode->next);

    // 释放内存
    cur = dummyNode->next;
    while (cur)
    {
        ListNode *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete dummyNode;

    return 0;
}
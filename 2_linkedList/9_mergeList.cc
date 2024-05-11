// 输入
// [3][1 2 4][3][1 3 4]
// 输出
// 1 1 2 3 4 4
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 迭代法
        ListNode *dummyNode = new ListNode(0);
        ListNode *pre = dummyNode;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                pre->next = list1;
                list1 = list1->next;
            }
            else
            {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        // 若list1为空连接到list2
        pre->next = list1 == nullptr ? list2 : list1;
        return dummyNode->next;
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

    // 构建链表list1
    for (int i = 0; i < length; i++)
    {
        cin >> item;
        ListNode *newNode = new ListNode(item);
        cur->next = newNode;
        cur = cur->next;
    }
    ListNode *list1 = dummyNode->next;

    // 构建链表list2
    cur = dummyNode;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> item;
        ListNode *newNode = new ListNode(item);
        cur->next = newNode;
        cur = cur->next;
    }
    ListNode *list2 = dummyNode->next;

    //
    // 解决方案
    //
    Solution solution;
    dummyNode->next = solution.mergeTwoLists(list1, list2);

    // 打印链表
    // printList(list1);
    // printList(list2);
    printList(dummyNode->next);

    // 释放内存
    // cur = dummyNode;
    // while (cur->next)
    // {
    //     ListNode *tmp = cur->next;
    //     cur = cur->next;
    //     delete tmp;
    // }
    // delete dummyNode;

    return 0;
}
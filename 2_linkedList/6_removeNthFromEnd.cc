// 输入
// [5][1 2 3 4 5][2]
// 输出
// [1 2 3 5]
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0);
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        dummyNode->next = head;

        while (n-- && fast->next != nullptr)
        {
            fast = fast->next;
        }
        fast = fast->next;

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

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
    int n;
    cin>>n;
    Solution solution;
    dummyNode->next = solution.removeNthFromEnd(dummyNode->next, 2);

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
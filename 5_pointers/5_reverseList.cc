// 输入: [5][1 2 3 4 5]
// 输出: [5 4 3 2 1]
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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main()
{
    int length;
    cin >> length;

    int item;

    ListNode *dummyNode = new ListNode(0);
    ListNode *cur = dummyNode;

    for (int i = 0; i < length; i++)
    {
        cin >> item;
        ListNode *newNode = new ListNode(item);
        cur->next = newNode;
        cur = cur->next;
    }

    Solution solution;
    dummyNode->next = solution.reverseList(dummyNode->next);

    cur = dummyNode->next;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

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
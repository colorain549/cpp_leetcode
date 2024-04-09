// 输入: [5][1 2 3 4 5]
// 输出: 1 2 3 5
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0);
        ListNode *cur = dummyNode;
        dummyNode->next = head;

        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;

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
    int length;
    cin >> length;

    ListNode *dummyNode = new ListNode(0);
    ListNode *cur = dummyNode;

    int item;

    for (int i = 0; i < length; i++)
    {
        cin >> item;
        ListNode *newNode = new ListNode(item);
        cur->next = newNode;
        cur = cur->next;
    }

    Solution solution;
    dummyNode->next = solution.removeNthFromEnd(dummyNode->next, 2);

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
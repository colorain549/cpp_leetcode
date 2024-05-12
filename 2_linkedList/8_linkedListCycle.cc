#include <iostream>

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
    ListNode *detectCycle(ListNode *head)
    {
        // 快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        // !!!循环条件尚不理解!!!
        while (fast != NULL && fast->next != NULL)
        {
            // 快指针走2步
            // 慢指针走1步
            fast = fast->next->next;
            slow = slow->next;
            // 快满指针相遇
            if (fast == slow)
            {
                // index1指向fast
                // index2指向head
                ListNode *index1 = fast;
                ListNode *index2 = head;
                // 计算入环节点
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};
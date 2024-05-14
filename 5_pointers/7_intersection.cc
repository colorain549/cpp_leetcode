#include <iostream>
#include <algorithm>

using std::swap;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        // 计算链表长度
        int lengthA = 0;
        int lengthB = 0;
        while (curA)
        {
            curA = curA->next;
            lengthA++;
        }
        while (curB)
        {
            curB = curB->next;
            lengthB++;
        }
        // 重置
        curA = headA;
        curB = headB;
        // 使链表A成为较长的链
        if (lengthA < lengthB)
        {
            swap(curA, curB);
            swap(lengthA, lengthB);
        }
        // 对齐
        int diff = lengthA - lengthB;
        while (diff--)
        {
            curA = curA->next;
        }
        // 计算相交位置
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
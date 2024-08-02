## 链表
 
2. 移除链表元素(203)
3. 设计链表(707)
4. 反转链表(206)
5. 两两交换链表中的节点(24)
6. 删除链表的倒数第N个节点(19)
7. 链表相交(160/面试题02.07)
8. 环形链表2(142)
9. [合并两个有序列表](https://leetcode.cn/problems/merge-two-sorted-lists/solutions/226408/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/)(21)
```
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
```

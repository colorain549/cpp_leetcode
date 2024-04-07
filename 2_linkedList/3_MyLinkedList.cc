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

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList()
    {
        _dummyNode = new ListNode(0);
        _length = 0;
    }

    int get(int index)
    {
        // 检查
        if (index < 0 || index > _length + 1)
        {
            return -1;
        }
        ListNode *cur = _dummyNode->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *tmp = _dummyNode->next;
        ListNode *newNode = new ListNode(val);
        _dummyNode->next = newNode;
        newNode->next = tmp;
        _length++;
    }

    void addAtTail(int val)
    {
        ListNode *cur = _dummyNode;
        while (cur->next)
        {
            cur = cur->next;
        }
        ListNode *newNode = new ListNode(val);
        cur->next = newNode;
        _length++;
    }

    void addAtIndex(int index, int val)
    {
        // 判断
        if (index < 0 || index > _length)
        {
            return;
        }
        ListNode *cur = _dummyNode;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        ListNode *newNode = new ListNode(val);
        cur->next = newNode;
        newNode->next = tmp;
        _length++;
    }

    void deleteAtIndex(int index)
    {
        // 检查
        if (index < 0 || index > _length - 1)
        {
            return;
        }
        ListNode *cur = _dummyNode;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // 保存要删除节点
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        // 释放内存
        delete tmp;
        _length--;
    }

    void printList()
    {
        ListNode *cur = _dummyNode->next;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void freeMemory()
    {
        ListNode *cur = _dummyNode;
        while (cur->next)
        {
            ListNode *tmp = cur->next;
            cur = cur->next;
            delete tmp;
        }
        delete _dummyNode;
    }

private:
    ListNode *_dummyNode;
    int _length;
};

int main()
{
    // 链表元素
    int item;

    // 创建哑节点
    ListNode *dummyNode = new ListNode(0);
    ListNode *cur = dummyNode;

    //
    // 解决方案
    MyLinkedList myLinkedList;
    // 1
    myLinkedList.addAtHead(1);
    myLinkedList.printList();

    // 1 3
    myLinkedList.addAtTail(3);
    myLinkedList.printList();

    // 1 2 3
    myLinkedList.addAtIndex(1, 2);
    myLinkedList.printList();

    // 2
    cout << myLinkedList.get(1) << endl;

    // 1 3
    myLinkedList.deleteAtIndex(1);
    myLinkedList.printList();

    // 3
    cout << myLinkedList.get(1) << endl;

    // 释放内存
    myLinkedList.freeMemory();
    delete dummyNode;

    return 0;
}
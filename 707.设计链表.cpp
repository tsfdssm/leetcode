/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct Node
    {
        int val;
        Node *pre;
        Node *nxt;
        Node(int _val) : val(_val), pre(nullptr), nxt(nullptr) {}
        Node() : val(0), pre(nullptr), nxt(nullptr) {}
    };
    Node *head;
    Node *tail;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->pre = head;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= size)
            return -1;
        Node *cur = head;
        while (index >= 0)
        {
            cur = cur->nxt;
            --index;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        addAtIndex(0, val);
        // Node *cur = new Node(val);
        // cur->nxt = head->nxt;
        // cur->pre = head;
        // head->nxt->pre = cur;
        // head->nxt = cur;
        // size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        addAtIndex(size, val);
        // Node *cur = new Node(val);
        // cur->nxt = tail;
        // cur->pre = tail->pre;
        // tail->pre->nxt = cur;
        // tail->pre = cur;
        // size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        Node *cur = new Node(val);
        Node *p = head;
        while (index > 0)
        {
            p = p->nxt;
            --index;
        }
        cur->nxt = p->nxt;
        cur->pre = p;
        cur->nxt->pre = cur;
        p->nxt = cur;
        ++size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        Node *cur = head;
        while (index >= 0)
        {
            cur = cur->nxt;
            --index;
        }
        cur->nxt->pre = cur->pre;
        cur->pre->nxt = cur->nxt;
        --size;
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (nullptr == head || nullptr == head->next)
            return head;
        ListNode *l = head, *r = head, *tmp = nullptr;
        int count = 0;
        while (r != nullptr && r->next != nullptr)
        {
            count++;
            l = l->next;
            r = r->next;
            if (r == nullptr)
                break;
            r = r->next;
        }

        if (8 > count)
        {
            ListNode *phead = new ListNode();
            //phead->next = head;
            while (nullptr != head)
            {
                ListNode *cur = phead, *tmp = head->next;
                while (cur->next != nullptr && cur->next->val < head->val)
                {
                    cur = cur->next;
                }
                head->next = cur->next;
                cur->next = head;
                head = tmp;
            }
            ListNode *res = phead->next;
            delete phead;
            return res;
        }
        else
        {
            ListNode *phead = new ListNode(), *cur = phead;

            tmp = l->next;
            l->next = nullptr;

            head = sortList(head);
            l = sortList(tmp);

            while (l != nullptr && head != nullptr)
            {
                if (l->val < head->val)
                {
                    cur->next = l;
                    l = l->next;
                    cur = cur->next;
                }
                else
                {
                    cur->next = head;
                    head = head->next;
                    cur = cur->next;
                }
            }
            if (l != nullptr)
                cur->next = l;
            else if (head != nullptr)
                cur->next = head;
            ListNode *res = phead->next;
            delete phead;
            return res;
        }
    }
};
// @lc code=end

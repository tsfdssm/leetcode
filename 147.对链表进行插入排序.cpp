/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode *insertionSortList(ListNode *head)
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
};
// @lc code=end

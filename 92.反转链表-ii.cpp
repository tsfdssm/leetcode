/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prehead = new ListNode(0, head);
        ListNode *pre = prehead, *tmp;
        int index = 1;
        bool first = true;
        for (; index < left; index++)
            pre = pre->next;
        head = pre->next;
        for (; index < right; index++)
        {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return prehead->next;
    }
};
// @lc code=end

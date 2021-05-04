/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *l = head, *r = head;
        int cnt = 0;
        while (l != nullptr && r != nullptr)
        {
            l = l->next;
            r = r->next;
            cnt++;
            if (r != nullptr)
                r = r->next;
            else
                return nullptr;
            if (l == r)
            {
                ListNode *tmp = head;
                while (tmp != l)
                {
                    tmp = tmp->next;
                    l = l->next;
                }
                return l;
            }
        }
        return nullptr;
    }
};
// @lc code=end

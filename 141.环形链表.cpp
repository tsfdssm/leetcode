/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head)
    {
        ListNode *l = head, *r = head;
        while (l != nullptr && r != nullptr)
        {
            l = l->next;
            r = r->next;
            if (r != nullptr)
                r = r->next;
            else
                return false;
            if (l == r)
                return true;
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *start = new ListNode(0);
        ListNode *p = l1, *q = l2, *cur = start;
        int over = 0;
        while (p != 0 || q != 0)
        {
            int x = p == 0 ? 0 : p->val;
            int y = q == 0 ? 0 : q->val;
            int sum = x + y + over;
            over = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (p != 0)
                p = p->next;
            if (q != 0)
                q = q->next;
        }
        if (over > 0)
            cur->next = new ListNode(over);
        return start->next;
    }
};
// @lc code=end

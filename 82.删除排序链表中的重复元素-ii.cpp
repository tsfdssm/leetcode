/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (nullptr == head || nullptr == head->next)
            return head;
        ListNode *tmp = head;
        ListNode *unique = new ListNode(-1000, head);
        ListNode *start = unique;
        int dup = -10000;
        while (nullptr != tmp)
        {
            if (dup == tmp->val)
            {
            }
            else if (nullptr != tmp->next && tmp->val == tmp->next->val)
            {
                dup = tmp->next->val;
            }
            else
            {
                unique = unique->next = tmp;
            }
            tmp = tmp->next;
        }
        unique->next = nullptr;
        return start->next;
    }
};
// @lc code=end

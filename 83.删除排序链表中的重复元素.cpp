/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        ListNode *tmp = head->next;
        ListNode *unique = head;
        while (nullptr != tmp)
        {
            if (unique->val != tmp->val)
            {
                unique = unique->next = tmp;
            }
            tmp = tmp->next;
        }
        unique->next = nullptr;
        return head;
    }
};
// @lc code=end

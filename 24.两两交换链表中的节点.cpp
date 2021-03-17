/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode phead(0, head), *cur = &phead, *tmp = nullptr;
        while (cur != nullptr && cur->next != nullptr && cur->next->next != nullptr)
        {
            tmp = cur->next->next;
            cur->next->next = cur->next->next->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        return phead.next;
    }
};
// @lc code=end

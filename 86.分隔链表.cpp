/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *cur = head;
        ListNode *pre = new ListNode(0, nullptr), *prehead = pre;
        ListNode *post = new ListNode(0, nullptr), *posthead = post;
        while (cur != nullptr)
        {
            if (cur->val < x)
            {
                pre->next = cur;
                pre = pre->next;
            }
            else
            {
                post->next = cur;
                post = post->next;
            }
            cur = cur->next;
        }
        post->next = nullptr;
        pre->next = posthead->next;

        return prehead->next;
    }
};
// @lc code=end

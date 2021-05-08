/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode *cur = nullptr;
    bool isPalindrome(ListNode *head)
    {
        cur = head;
        return recurList(head);
    }

    bool recurList(ListNode *now)
    {

        if (nullptr != now)
        {

            if (!recurList(now->next))
                return false;
            if (cur->val != now->val)
                return false;

            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end

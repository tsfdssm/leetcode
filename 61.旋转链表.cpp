/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        int n = 1;
        ListNode *tmp = head;
        while (tmp->next != nullptr)
        {
            n++;
            tmp = tmp->next;
        }
        k %= n;
        k = n - k;
        tmp->next = head;
        for (int i = 0; i < k; i++)
        {
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = nullptr;
        return head;
    }
};
// @lc code=end

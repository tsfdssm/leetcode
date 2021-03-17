/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *now = nullptr;

        if (!l1 && !l2)
            return nullptr;
        else if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else if (l1->val < l2->val)
        {
            now = head = l1;
            l1 = l1->next;
        }
        else
        {
            now = head = l2;
            l2 = l2->next;
        }
        while (l1 || l2)
        {
            if (!l1)
            {
                now->next = l2;
                break;
            }
            else if (!l2)
            {
                now->next = l1;
                break;
            }
            else
            {
                if (l1->val <= l2->val)
                {
                    now->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    now->next = l2;
                    l2 = l2->next;
                }
                now = now->next;
            }
        }
        return head;
    }
};
// @lc code=end

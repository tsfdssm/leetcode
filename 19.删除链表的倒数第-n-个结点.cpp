/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head->next == nullptr)
            return nullptr;

        ListNode *head0 = head;
        ListNode *head2 = head;

        for (int num = 0; num < n; num++)
        {
            head2 = head2->next;
            if (!head2)
                return head0->next;
        }
        while (head)
        {
            if (head2->next)
            {

                head2 = head2->next;
                head = head->next;
            }
            else
            {
                if (head->next->next)
                {
                    head->next = head->next->next;
                }
                else
                {
                    head->next = nullptr;
                }
                break;
            }
        }
        return head0;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode *, ListNode *> Reverse(ListNode *head, ListNode *tail)
    {
        ListNode *after = tail->next;
        ListNode *before = head;
        ListNode *tmp = nullptr;
        while (after != tail)
        {
            tmp = before->next;
            before->next = after;
            after = before;
            before = tmp;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *phead = new ListNode(0, head);
        ListNode *pre = phead;
        while (head)
        {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                    return phead->next;
            }

            ListNode *nex = tail->next;
            tie(head, tail) = Reverse(head, tail);

            pre->next = head;
            tail->next = nex;

            pre = tail;
            head = tail->next;
        }
        return phead->next;
    }
};
// @lc code=end

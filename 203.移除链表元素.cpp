/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *pre = new ListNode(-1, head), *prehead = pre;

        while (head != nullptr)
        {
            if (head->val == val)
            {
                head = head->next;
                delete pre->next;
                pre->next = head;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }

        ListNode *tmp = prehead->next;
        delete prehead;
        return tmp;
    }
};
// @lc code=end

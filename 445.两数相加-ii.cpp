/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1;
        stack<int> st2;

        while (l1)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *p = nullptr;
        int over = 0;
        while (!st1.empty() || !st2.empty() || over)
        {
            int n1 = 0;
            int n2 = 0;
            if (!st1.empty())
            {
                n1 = st1.top();
                st1.pop();
            }

            if (!st2.empty())
            {
                n2 = st2.top();
                st2.pop();
            }
            int tmpN = (over + n1 + n2);
            over = tmpN / 10;
            ListNode *tmp = new ListNode();
            tmp->next = p;
            tmp->val = tmpN % 10;
            p = tmp;
        }
        return p;
    }
};
// @lc code=end

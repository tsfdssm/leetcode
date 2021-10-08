/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        int n = 0;
        auto cur = head;
        while (cur)
        {
            ++n;
            cur = cur->next;
        }
        vector<int> res(n);
        int idx = 0;
        stack<pair<int, int>> stk;
        cur = head;
        while (cur)
        {
            while (!stk.empty() && stk.top().first < cur->val)
            {
                auto [_, pos] = stk.top();
                res[pos] = cur->val;
                stk.pop();
            }
            stk.push({cur->val, idx});
            ++idx;
            cur = cur->next;
        }
        while (!stk.empty())
        {
            auto [_, pos] = stk.top();
            res[pos] = 0;
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

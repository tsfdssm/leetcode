/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> mp;
        for (int num : nums)
            mp.emplace(num);
        bool flag = false;
        int cnt = 0;
        while (head)
        {
            if (flag)
            {
                if (mp.count(head->val))
                {
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                if (mp.count(head->val))
                {
                    flag = true;
                    cnt++;
                }
                else
                {
                }
            }
            head = head->next;
        }
        return cnt;
    }
};
// @lc code=end

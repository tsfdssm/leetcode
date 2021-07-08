/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *cur = head;
        int cnt = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            cnt++;
        }
        int len = cnt / k + 1;
        int num = cnt % k;
        cur = head;
        ListNode *pre = nullptr;
        vector<ListNode *> res;
        for (int i = 0; i < k; ++i)
        {

            if (i < num)
            {
                res.emplace_back(cur);
                for (int j = 0; j < len - 1; ++j)
                    cur = cur->next;
                pre = cur;
                cur = cur->next;
                pre->next = nullptr;
            }
            else
            {
                res.emplace_back(cur);
                if (cur != nullptr)
                {
                    for (int j = 0; j < len - 2; ++j)
                        cur = cur->next;
                    pre = cur;
                    cur = cur->next;
                    pre->next = nullptr;
                }
            }
        }
        return res;
    }
};
// @lc code=end

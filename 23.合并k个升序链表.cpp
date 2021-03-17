/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *phead = new ListNode(-1);
        ListNode *pcur = phead;
        vector<bool> flag(lists.size(), false);
        while (1)
        {
            int min = 10e6;
            int tmp = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (flag[i])
                    continue;
                if (lists[i] == nullptr)
                {
                    flag[i] = true;
                    continue;
                }

                if (lists[i]->val < min)
                {
                    min = lists[i]->val;
                    tmp = i;
                }
            }
            if (min == 10e6)
                break;

            pcur->next = lists[tmp];
            lists[tmp] = lists[tmp]->next;
            pcur = pcur->next;
        }
        return phead->next;
    }
};
// @lc code=end

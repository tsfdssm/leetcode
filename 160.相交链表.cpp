/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    unordered_set<ListNode *> st;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (nullptr != headA || nullptr != headB)
        {
            if (nullptr != headA)
            {
                if (st.find(headA) != st.end())
                {
                    return headA;
                }
                st.insert(headA);
                headA = headA->next;
            }
            if (nullptr != headB)
            {
                if (st.find(headB) != st.end())
                {
                    return headB;
                }
                st.insert(headB);

                headB = headB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

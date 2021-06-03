/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *phead = nullptr;
    Solution(ListNode *head)
    {
        this->phead = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *tmp = phead;
        int n = random() % getLenth(phead);

        for (int i = 0; i < n; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    int getLenth(ListNode *head)
    {
        int res = 0;
        while (nullptr != head)
        {
            head = head->next;
            ++res;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * 
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

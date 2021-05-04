/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode *head)
    {
        // if (head == nullptr)
        // {
        //     return;
        // }
        // vector<ListNode *> vec;
        // ListNode *node = head;
        // while (node != nullptr)
        // {
        //     vec.emplace_back(node);
        //     node = node->next;
        // }
        // int i = 0, j = vec.size() - 1;
        // while (i < j)
        // {
        //     vec[i]->next = vec[j];
        //     i++;
        //     if (i == j)
        //     {
        //         break;
        //     }
        //     vec[j]->next = vec[i];
        //     j--;
        // }
        // vec[i]->next = nullptr;
        /*********************************************************************/
        // if (nullptr == head)
        //     return;
        // vector<ListNode *> pList;

        // ListNode *phead = head;
        // //ListNode *phead = new ListNode(-1, head);

        // while (nullptr != head)
        // {
        //     pList.push_back(head);
        //     head = head->next;
        // }
        // int l = 0, r = (pList.size() - 1);

        // while (l < r)
        // {

        //     pList[l]->next = pList[r];
        //     //phead = phead->next;
        //     l++;

        //     if (l == r)
        //         break;
        //     pList[r]->next = pList[l];
        //     r--;
        // }
        // pList[l]->next = nullptr;
        // return;
        /***********************************************************/
        if (nullptr == head)
            return;
        vector<ListNode *> pList;

        ListNode *phead = head;
        //ListNode *phead = new ListNode(-1, head);

        head = head->next;
        while (nullptr != head)
        {
            pList.push_back(head);
            head = head->next;
        }
        int l = 0, r = (pList.size() - 1);

        while (l <= r)
        {

            phead->next = pList[r];
            phead = phead->next;
            r--;

            if (l > r)
                break;
            phead->next = pList[l];
            phead = phead->next;
            l++;
        }
        phead->next = nullptr;
        return;
    }
};
// @lc code=end

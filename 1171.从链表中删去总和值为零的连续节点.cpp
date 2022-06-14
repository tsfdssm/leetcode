/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
 *
 * https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (48.13%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    16.4K
 * Total Submissions: 34.1K
 * Testcase Example:  '[1,2,-3,3,1]'
 *
 * 给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
 *
 * 删除完毕后，请你返回最终结果链表的头节点。
 *
 *
 *
 * 你可以返回任何满足题目要求的答案。
 *
 * （注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
 *
 * 示例 1：
 *
 * 输入：head = [1,2,-3,3,1]
 * 输出：[3,1]
 * 提示：答案 [1,2,1] 也是正确的。
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2,3,-3,4]
 * 输出：[1,2,4]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1,2,3,-3,-2]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给你的链表中可能有 1 到 1000 个节点。
 * 对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.
 *
 *
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *phead = new ListNode(-1, head);
        unordered_map<int, ListNode *> mp;
        stack<ListNode *> stk;
        int sum = 0;
        stk.push(phead);
        mp[0] = phead;
        ListNode *cur = head;
        while (cur)
        {
            sum += cur->val;
            if (mp.count(sum))
            {
                int tmp = sum;
                sum -= cur->val;
                while (stk.top() != mp[tmp])
                {
                    mp.erase(sum);
                    sum -= stk.top()->val;
                    stk.pop();
                }
                stk.top()->next = cur->next;
            }
            else
            {
                mp[sum] = cur;
                stk.push(cur);
            }
            cur = cur->next;
        }
        return phead->next;
    }
};
// @lc code=end

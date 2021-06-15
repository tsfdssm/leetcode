/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    // Node *dfs(Node *pre, Node *cur)
    // {
    //     if (nullptr == cur)
    //         return pre;
    //     pre->next = cur;
    //     cur->prev = pre;

    //     Node *tmpNext = cur->next;
    //     Node *tail = dfs(cur, cur->child);
    //     cur->child = nullptr;
    //     return dfs(tail, tmpNext);
    // }
    Node *flatten(Node *head)
    {
        if (nullptr == head)
            return nullptr;
        Node *phead = new Node();
        dfs(phead, head);

        phead->next->prev = nullptr;
        return phead->next;
    }
};
// @lc code=end

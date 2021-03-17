/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    //vector<Node *> list;
    Node *copyRandomList(Node *head)
    {
        if (nullptr == head)
            return nullptr;
        if (mp.find(head) != mp.end())
            return mp[head];
        Node *newNode = new Node(head->val);
        mp[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};
// @lc code=end

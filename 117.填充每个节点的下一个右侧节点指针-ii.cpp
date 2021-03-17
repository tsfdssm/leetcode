/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (nullptr == root)
            return nullptr;
        Node *start = root;
        while (nullptr != start)
        {
            Node *nextStart = nullptr, *last = nullptr;
            for (Node *p = start; nullptr != p; p = p->next)
            {
                if (nullptr != p->left)
                {
                    if (nullptr == nextStart)
                        nextStart = p->left;
                    if (nullptr != last)
                        last->next = p->left;
                    last = p->left;
                }
                if (nullptr != p->right)
                {
                    if (nullptr == nextStart)
                        nextStart = p->right;
                    if (nullptr != last)
                        last->next = p->right;
                    last = p->right;
                }
            }
            start = nextStart;
        }
        return root;
        // if (nullptr == root)
        //     return nullptr;
        // queue<Node *> q;
        // q.push(root);
        // while (false == q.empty())
        // {
        //     int len = q.size();
        //     for (int i = 0; i < len; i++)
        //     {
        //         Node *tmp = q.front();
        //         q.pop();
        //         if (i == (len - 1))
        //             tmp->next = nullptr;
        //         else
        //             tmp->next = q.front();

        //         if (nullptr != tmp->left)
        //             q.push(tmp->left);
        //         if (nullptr != tmp->right)
        //             q.push(tmp->right);
        //     }
        // }
        // return root;
    }
};
// @lc code=end

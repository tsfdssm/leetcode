/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        if (nullptr == root)
            return {};
        stack<Node *> stk;
        stk.push(root);
        deque<int> res;
        while (!stk.empty())
        {
            const auto cur = stk.top();
            res.push_front(cur->val);
            const auto &chi = cur->children;
            stk.pop();
            for (auto it = chi.begin(); it != chi.end(); ++it)
            {
                stk.push(*it);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

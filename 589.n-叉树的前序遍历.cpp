/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node *root)
    {
        if (nullptr == root)
            return {};
        stack<Node *> stk;
        stk.push(root);
        vector<int> res;
        while (!stk.empty())
        {
            const auto cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            const auto &chi = cur->children;
            for (auto it = chi.rbegin(); it != chi.rend(); ++it)
                stk.push(*it);
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (nullptr == root)
            return res;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; ++i)
            {
                const auto &cur = q.front();
                tmp.push_back(cur->val);
                for (auto &child : cur->children)
                    q.push(child);
                q.pop();
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

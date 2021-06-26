/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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
    int dfs(Node *root)
    {
        if (nullptr == root)
            return 0;
        int maxn = 0;
        for (auto child : root->children)
        {
            maxn = max(maxn, dfs(child));
        }
        return maxn + 1;
    }
    int maxDepth(Node *root)
    {
        return dfs(root);
    }
};
// @lc code=end

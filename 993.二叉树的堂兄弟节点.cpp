/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        int dx = -1;
        int dy = -1;
        int fx = -1;
        int fy = -1;
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *cur, int f, int d) {
            if (nullptr == cur)
                return;
            if (cur->val == x)
            {
                dx = d;
                fx = f;
            }
            else if (cur->val == y)
            {
                dy = d;
                fy = f;
            }
            dfs(cur->left, cur->val, d + 1);
            dfs(cur->right, cur->val, d + 1);
        };
        dfs(root, -1, 0);
        return dx == dy && fx != fy;
    }
};
// @lc code=end

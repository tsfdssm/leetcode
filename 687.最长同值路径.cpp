/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int res = 0;
    int dfs(TreeNode *root, int cur)
    {
        if (nullptr == root)
            return 0;
        if (cur == root->val)
        {
            int l = dfs(root->left, cur);
            int r = dfs(root->right, cur);
            res = max(res, l + r);
            return 1 + max(l, r);
        }
        else
        {
            int tmp = dfs(root->left, root->val) + dfs(root->right, root->val);
            res = max(res, tmp);
            return 0;
        }
    }
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root, -1);
        return res;
    }
};
// @lc code=end

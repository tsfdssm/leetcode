/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    pair<int, int> dfs(TreeNode *root)
    {
        if (nullptr == root)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int select = root->val + l.second + r.second;
        int notSelect = max(l.first, l.second) + max(r.first, r.second);
        return make_pair(select, notSelect);
    }
    int rob(TreeNode *root)
    {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    pair<bool, bool> dfs(TreeNode *root) //has ,be;
    {
        if (nullptr == root)
            return {false, true};
        auto [lhas, lbe] = dfs(root->left);
        auto [rhas, rbe] = dfs(root->right);
        if (false == lbe || false == rbe)
        {
            ++res;
            return {true, true};
        }
        if (true == lhas || true == rhas)
            return {false, true};
        return {false, false};
    }
    int minCameraCover(TreeNode *root)
    {
        auto [has, be] = dfs(root);
        if (false == be)
            ++res;
        return res;
    }
};
// @lc code=end

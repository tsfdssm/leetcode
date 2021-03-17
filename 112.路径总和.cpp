/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool flag = false;
    void dfs(TreeNode *root, int cur)
    {
        if (true == flag)
            return;
        if (nullptr == root)
            return;
        if (cur == root->val && nullptr == root->left && nullptr == root->right)
            flag = true;
        dfs(root->left, cur - root->val);
        dfs(root->right, cur - root->val);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return flag;
    }
};
// @lc code=end

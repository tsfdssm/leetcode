/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    int val;
    bool dfs(TreeNode *root)
    {

        if (nullptr == root)
            return true;
        if (root->val != val)
            return false;
        return dfs(root->left) && dfs(root->right);
    }
    bool isUnivalTree(TreeNode *root)
    {
        if (nullptr == root)
            return true;
        val = root->val;
        return dfs(root);
    }
};
// @lc code=end

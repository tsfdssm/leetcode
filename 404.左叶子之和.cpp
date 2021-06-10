/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        return dfs(root, false);
    }
    int dfs(TreeNode *root, bool left)
    {
        if (nullptr == root)
            return 0;
        if (nullptr == root->left && nullptr == root->right)
            if (left)
                return root->val;
            else
                return 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};
// @lc code=end

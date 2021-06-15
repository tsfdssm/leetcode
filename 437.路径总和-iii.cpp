/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (nullptr == root)
            return 0;
        return dfs(0, targetSum, root) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(int sum, int target, TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        sum += root->val;
        return dfs(sum, target, root->left) + dfs(sum, target, root->right) + ((sum == target) ? 1 : 0);
    }
};
// @lc code=end

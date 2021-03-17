/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxSum = INT_MIN;
    int maxVal(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        int left = max(maxVal(root->left), 0);
        int right = max(maxVal(root->right), 0);

        int total = root->val + left + right;

        maxSum = max(maxSum, total);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        maxVal(root);
        return maxSum;
    }
};
// @lc code=end

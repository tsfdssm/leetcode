/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    void dfs(TreeNode *root, int cur)
    {
        if (nullptr == root)
        {
            return;
        }
        cur *= 2;
        cur += root->val;
        if (nullptr == root->left && nullptr == root->right)
        {
            res += cur;
            return;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end

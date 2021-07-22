/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int res = INT_MAX;
    int last = -1e4;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        dfs(root->left);

        res = min(res, root->val - last);
        last = root->val;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end

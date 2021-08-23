/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int l, r;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        if (root->val < l)
        {
            dfs(root->right);
        }
        else if (root->val > r)
        {
            dfs(root->left);
        }
        else
        {
            res += root->val;
            dfs(root->left);
            dfs(root->right);
        }
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        l = low;
        r = high;
        dfs(root);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode *pruneTree(TreeNode *root)
    {
        if (nullptr == root)
            return nullptr;
        TreeNode *l = pruneTree(root->left);
        TreeNode *r = pruneTree(root->right);
        root->left = l;
        root->right = r;
        if ((l == nullptr) && (r == nullptr) && (0 == root->val))
            return nullptr;
        return root;
    }
};
// @lc code=end

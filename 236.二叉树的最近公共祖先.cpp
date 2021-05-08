/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p == root || q == root)
            return root;
        if (root != nullptr)
        {
            TreeNode *l = lowestCommonAncestor(root->left, p, q);
            TreeNode *r = lowestCommonAncestor(root->right, p, q);
            if (nullptr != l && nullptr != r)
                return root;
            if (nullptr != l)
            {
                return l;
            }
            else
            {
                return r;
            }
        }
        return nullptr;
    }
};
// @lc code=end

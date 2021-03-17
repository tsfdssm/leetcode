/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymetric2(TreeNode *l, TreeNode *r)
    {
        if (nullptr == l && nullptr == r)
            return true;
        if (nullptr == l || nullptr == r)
            return false;
        return (isSymetric2(l->left, r->right) && (l->val == r->val) && isSymetric2(l->right, r->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (nullptr == root)
            return true;
        return isSymetric2(root->left, root->right);
    }
};
// @lc code=end

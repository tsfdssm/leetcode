/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *res = nullptr;
    TreeNode *f = nullptr;
    void inorder(TreeNode *root)
    {
        if (nullptr == root)
            return;
        inorder(root->left);
        root->left = nullptr;
        TreeNode *tmp = root->right;
        if (nullptr == f)
        {
            res = f = root;
        }
        else
        {
            f->right = root;
            f = root;
        }
        inorder(tmp);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        inorder(root);
        return res;
    }
};
// @lc code=end

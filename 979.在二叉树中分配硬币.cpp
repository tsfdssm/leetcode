/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int diff(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        return root->val - 1 + diff(root->left) + diff(root->right);
    }

    int check(TreeNode *root, int c)
    {
        if (nullptr == root)
            return 0;
        int l = diff(root->left);
        int r = diff(root->right);
        //l+r+root->val-1=c;
        return abs(l) + abs(r) + check(root->left, l) + check(root->right, r);
    }

    int distributeCoins(TreeNode *root)
    {
        return check(root, 0);
    }
};
// @lc code=end

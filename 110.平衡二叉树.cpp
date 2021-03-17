/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int balance(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        int l = balance(root->left);
        if (-1 == l)
            return -1;
        int r = balance(root->right);
        if (-1 == r)
            return -1;
        else if (l - r > 1 || r - l > 1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (nullptr == root)
            return true;
        if (-1 == balance(root))
            return false;
        return true;
    }
};
// @lc code=end

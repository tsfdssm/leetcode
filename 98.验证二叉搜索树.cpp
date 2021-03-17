/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long long min = (long long)INT_MIN - 1;
    bool isValidBST(TreeNode *root)
    {
        if (nullptr == root)
            return true;
        if (false == isValidBST(root->left))
            return false;
        if (min >= (long long)root->val)
            return false;
        min = (long long)root->val;
        return isValidBST(root->right);
    }
};
// @lc code=end

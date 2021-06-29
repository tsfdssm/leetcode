/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode *root)
    {
        if (nullptr == root)
            return "()";
        string res = to_string(root->val);
        if (nullptr == root->left && nullptr == root->right)
            return res;
        string left;
        string right;
        if (nullptr != root->left)
            left = "(" + tree2str(root->left) + ")";
        else
            left = "()";
        if (nullptr != root->right)
            right = "(" + tree2str(root->right) + ")";
        else
            right = "";
        return res + left + right;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (nullptr == root)
            return {};
        if (nullptr == root->left && nullptr == root->right)
            return {to_string(root->val)};
        vector<string> res;
        vector<string> l = binaryTreePaths(root->left);
        vector<string> r = binaryTreePaths(root->right);
        if (nullptr != root->left)
            res.insert(res.end(), l.begin(), l.end());
        if (nullptr != root->right)
            res.insert(res.end(), r.begin(), r.end());
        for (string &s : res)
            s = to_string(root->val) + "->" + s;
        return res;
    }
};
// @lc code=end

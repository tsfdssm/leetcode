/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode *t = new TreeNode();
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        TreeNode *l = root->left, *r = root->right;
        t->right = root;
        t->left = nullptr;
        t = t->right;
        dfs(l);
        dfs(r);
        return;
    }
    void flatten(TreeNode *root)
    {
        dfs(root);
    }
};
// @lc code=end

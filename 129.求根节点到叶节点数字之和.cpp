/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int res = 0;
    int tmp = 0;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        tmp *= 10;
        tmp += root->val;
        if (nullptr == root->left && nullptr == root->right)
        {
            res += tmp;
        }
        //if (nullptr != root->left)
        dfs(root->left);
        //if (nullptr != root->right)
        dfs(root->right);
        tmp /= 10;
    }
    int sumNumbers(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end

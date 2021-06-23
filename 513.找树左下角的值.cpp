/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxlevel = -1;
    void dfs(TreeNode *root, int level)
    {
        if (nullptr == root)
            return;
        if (level > maxlevel)
        {
            maxlevel = level;
            res = root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(TreeNode *root, int cur)
    {
        if (nullptr == root)
            return;
        tmp.push_back(root->val);
        if (cur == root->val && nullptr == root->left && nullptr == root->right)
        {
            res.emplace_back(tmp);
        }
        dfs(root->left, cur - root->val);
        dfs(root->right, cur - root->val);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return res;
    }
};
// @lc code=end

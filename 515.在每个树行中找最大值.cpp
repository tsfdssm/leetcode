/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> res;
    void dfs(TreeNode *root, int l)
    {
        if (nullptr == root)
            return;
        if (res.size() <= l)
        {
            res.push_back(root->val);
        }
        else
        {
            res[l] = max(res[l], root->val);
        }
        dfs(root->left, l + 1);
        dfs(root->right, l + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end

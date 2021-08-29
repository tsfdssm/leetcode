/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    int idx = 0;
    vector<int> res;
    bool dfs(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr || idx >= vec.size())
            return true;
        if (vec[idx] != root->val)
            return false;
        ++idx;
        if (nullptr != root->left && vec[idx] != root->left->val)
        {
            res.emplace_back(root->val);
            return dfs(root->right, vec) && dfs(root->left, vec);
        }
        else
        {
            return dfs(root->left, vec) && dfs(root->right, vec);
        }
    }
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        if (dfs(root, voyage))
            return res;
        return {-1};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxCnt = 0;
    int cnt = 0;
    int base = 0;
    void update(int x)
    {
        if (x == base)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            base = x;
        }
        if (cnt == maxCnt)
            res.push_back(x);
        else if (cnt > maxCnt)
        {
            maxCnt = cnt;
            res = {base};
        }
    }
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end

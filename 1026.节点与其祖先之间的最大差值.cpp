/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    map<int, int> mp;
    int res = 0;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        if (!mp.empty())
        {
            int minn = mp.begin()->first;
            int maxn = mp.rbegin()->first;
            res = max(res, abs(root->val - minn));
            res = max(res, abs(root->val - maxn));
        }
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
        if (0 == mp[root->val])
        {
            mp.erase(root->val);
        }
        return;
    }
    int maxAncestorDiff(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end

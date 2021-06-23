/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    unordered_map<int, int> mp;
    int dfs(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        root->val += dfs(root->left) + dfs(root->right);
        mp[root->val]++;
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        dfs(root);
        int maxn = 0;
        for (const auto &it : mp)
        {
            if (it.second < maxn)
                continue;
            if (it.second > maxn)
            {
                maxn = it.second;
                res = {it.first};
            }
            else
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
// @lc code=end

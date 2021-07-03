/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode *> res;
    map<tuple<int, int, int>, int> tree;
    unordered_map<int, int> cnt;
    int uid = 0;
    int dfs(TreeNode *root)
    {
        if (nullptr == root)
            return -1;
        auto t = make_tuple(root->val, dfs(root->left), dfs(root->right));
        if (!tree.count(t))
            tree[t] = uid++;
        int cur = tree[t];
        cnt[cur]++;
        if (2 == cnt[cur])
            res.push_back(root);
        return cur;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end

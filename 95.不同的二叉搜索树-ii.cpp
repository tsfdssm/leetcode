/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<vector<vector<TreeNode *>>> mem;

    vector<TreeNode *> generateTrees(int st, int ed)
    {
        vector<TreeNode *> res;
        if (st > ed)
            return {nullptr};
        if (mem[st][ed].empty() == false)
            return mem[st][ed];
        for (int i = st; i <= ed; ++i)
            for (auto &l : generateTrees(st, i - 1))
                for (auto &r : generateTrees(i + 1, ed))
                {
                    TreeNode *root = new TreeNode(i, l, r);
                    res.emplace_back(root);
                }
        return mem[st][ed] = res;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (0 == n)
            return {};
        mem.resize(n + 1, vector<vector<TreeNode *>>(n + 1));
        return generateTrees(1, n);
    }
};
// @lc code=end

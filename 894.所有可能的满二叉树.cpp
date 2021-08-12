/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (0 == n)
            return {};

        if (1 == n)
            return {new TreeNode(0)};
        --n;
        vector<TreeNode *> res;
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> l = allPossibleFBT(i);
            vector<TreeNode *> r = allPossibleFBT(n - i);
            for (int j = 0; j < l.size(); ++j)
                for (int k = 0; k < r.size(); ++k)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l[j];
                    root->right = r[k];
                    res.emplace_back(root);
                }
        }
        return res;
    }
};
// @lc code=end

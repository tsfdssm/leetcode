/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    TreeNode *solve(vector<int> &vec, int l, int r)
    {
        if (r < l)
            return nullptr;
        TreeNode *root = new TreeNode(vec[l]);
        int idx = l + 1;
        while (idx <= r && vec[idx] < vec[l])
            ++idx;
        root->left = solve(vec, l + 1, idx - 1);
        root->right = solve(vec, idx, r);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return solve(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end

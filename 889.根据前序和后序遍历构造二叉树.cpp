/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *construct(vector<int> &preorder, int prel, int prer, vector<int> &postorder, int postl, int postr)
    {
        if (prer == prel)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[prel]);
        if (prer == prel + 1)
            return root;

        int sz = 0;
        while (postorder[postl + sz] != preorder[prel + 1])
            sz++;
        ++sz;
        root->left = construct(preorder, prel + 1, prel + 1 + sz, postorder, postl, postl + sz);
        root->right = construct(preorder, prel + 1 + sz, prer, postorder, postl + sz, postr - 1);

        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return construct(preorder, 0, preorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

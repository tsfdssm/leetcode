/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int cnt = 0;
    int res = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        res = k;
        return inorder(root)->val;
    }

    TreeNode *inorder(TreeNode *root)
    {
        if (nullptr == root)
            return nullptr;
        TreeNode *tmp = inorder(root->left);
        if (nullptr != tmp)
            return tmp;
        ++cnt;
        if (cnt == res)
            return root;
        return inorder(root->right);
    }
};
// @lc code=end

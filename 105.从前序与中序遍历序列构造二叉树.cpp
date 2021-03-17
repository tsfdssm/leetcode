/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> index;
    TreeNode *preOrderConstruct(vector<int> &pre, int pl, int pr, vector<int> &in, int il, int ir)
    {
        if (pl >= pr || il >= ir)
            return nullptr;
        int rootval = pre[pl];
        TreeNode *root = new TreeNode(rootval);
        if (index.find(rootval) == index.end())
            return nullptr;
        int rootIndex = index[rootval];
        int lsize = rootIndex - il;
        root->left = preOrderConstruct(pre, pl + 1, pl + lsize + 1, in, il, rootIndex);
        root->right = preOrderConstruct(pre, pl + lsize + 1, pr, in, rootIndex + 1, ir);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() != inorder.size())
            return nullptr;

        for (int i = 0; i < preorder.size(); ++i)
            index[inorder[i]] = i;
        return preOrderConstruct(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

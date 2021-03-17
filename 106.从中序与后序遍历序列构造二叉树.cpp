/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *postOrderConstruct(vector<int> &post, int pl, int pr, vector<int> &in, int il, int ir)
    {
        if (pl >= pr || il >= ir)
            return nullptr;
        int rootval = post[pr - 1];
        TreeNode *root = new TreeNode(rootval);
        if (index.find(rootval) == index.end())
            return nullptr;
        int rootIndex = index[rootval];
        int lsize = rootIndex - il;
        root->left = postOrderConstruct(post, pl, pl + lsize, in, il, rootIndex);
        root->right = postOrderConstruct(post, pl + lsize, pr - 1, in, rootIndex + 1, ir);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        //if (postorder.size() != inorder.size())
        //    return nullptr;
        for (int i = 0; i < inorder.size(); ++i)
            index[inorder[i]] = i;
        return postOrderConstruct(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

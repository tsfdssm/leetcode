/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
public:
    vector<TreeNode *> vec;
    int n = 0;
    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }
    void inorder(TreeNode *root)
    {
        if (nullptr == root)
            return;
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);
    }

    int next()
    {
        int tmp = vec[n]->val;
        n++;
        return tmp;
    }

    bool hasNext()
    {
        return n < vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

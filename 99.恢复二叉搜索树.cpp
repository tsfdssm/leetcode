/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    bool first = true;
    TreeNode *min = nullptr;
    TreeNode *l = nullptr;
    TreeNode *r = nullptr;
    bool f1 = false, f2 = false;

    void recoverTree2(TreeNode *root)
    {
        if (nullptr == root || f2)
            return;
        recoverTree2(root->left);
        if (first)
        {
            first = false;
            min = root;
        }
        if (min->val > root->val)
        {
            if (false == f1)
            {
                f1 = true;
                l = min;
                r = root;
            }
            else
            {
                f2 = true;
                r = root;
            }
        }
        min = root;
        recoverTree2(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        recoverTree2(root);
        if (f1)
        {
            swap(l->val, r->val);
            return;
        }
        return;
    }
};
// @lc code=end

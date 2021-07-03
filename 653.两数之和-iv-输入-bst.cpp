/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    unordered_set<int> st;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        st.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    // bool findOne(TreeNode *root, int k)
    // {
    //     if (nullptr == root)
    //         return false;
    //     if (root->val == k)
    //         return true;
    //     if (k > root->val)
    //         return findOne(root->right, k);
    //     return findOne(root->left, k);
    // }
    bool findTarget(TreeNode *root, int k)
    {
        dfs(root);
        for (auto num : st)
        {
            if (k != 2 * num && st.count(k - num))
                return true;
        }
        return false;
        // if (nullptr == root)
        //     return false;
        // if ((k <= 2 * root->val) && findOne(root->left, k - root->val))
        //     return true;
        // if ((k >= 2 * root->val) && findOne(root->right, k - root->val))
        //     return true;
        // return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    set<int> st;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
            return;
        dfs(root->left);
        st.insert(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        auto it1 = st.begin();
        auto it2 = it1;
        ++it2;
        int res = INT_MAX;
        while (it2 != st.end())
        {
            res = min(res, *it2 - *it1);
            ++it1;
            ++it2;
        }
        return res;
    }
};
// @lc code=end

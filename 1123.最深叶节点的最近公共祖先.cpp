/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    int getHeight(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int maxL = getHeight(root);
        TreeNode *res = root;
        function<bool(TreeNode *, int)> dfs = [&](TreeNode *root, int level) {
            if (nullptr == root)
                return level == maxL;
            auto l = dfs(root->left, level + 1);
            auto r = dfs(root->right, level + 1);
            if (l && r)
            {
                res = root;
                return true;
            }
            else if (l || r)
                return true;
            return false;
        };
        dfs(root, 0);
        return res;
    }
};
// @lc code=end

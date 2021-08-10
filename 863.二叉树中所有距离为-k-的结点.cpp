/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> res;
    void dist_dfs(TreeNode *root, int dist)
    {
        if (nullptr == root)
            return;
        if (0 == dist)
        {
            res.emplace_back(root->val);
        }
        else
        {
            dist_dfs(root->left, dist - 1);
            dist_dfs(root->right, dist - 1);
        }
    }
    TreeNode *t;
    int distance;

    int dfs(TreeNode *root)
    {
        if (nullptr == root)
            return -1;
        if (root == t)
        {
            dist_dfs(root, distance);
            return 1;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (-1 != l)
        {
            if (l == distance)
            {
                res.emplace_back(root->val);
            }
            else if (l < distance)
            {
                dist_dfs(root->right, distance - l - 1);
            }
            else
            {
            }
            return l + 1;
        }
        else if (-1 != r)
        {
            if (r == distance)
            {
                res.emplace_back(root->val);
            }
            else if (r < distance)
            {
                dist_dfs(root->left, distance - r - 1);
            }
            else
            {
            }
            return r + 1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        t = target;
        distance = k;
        dfs(root);
        return res;
    }
};
// @lc code=end

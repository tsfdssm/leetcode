/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    // int min1 = -1;
    // int min2 = -1;
    // void dfs(TreeNode *root)
    // {
    //     if (nullptr == root)
    //         return;
    //     if (min1 == -1)
    //         min1 = root->val;
    //     else
    //     {
    //         if (min1 > root->val)
    //         {
    //             min2 = min1;
    //             min1 = root->val;
    //         }
    //         else if (min1 < root->val)
    //         {
    //             if (min2 == -1)
    //                 min2 = root->val;
    //             else
    //             {
    //                 min2 = min(min2, root->val);
    //             }
    //         }
    //         else
    //         {
    //         }
    //     }
    //     dfs(root->left);
    //     dfs(root->right);
    // }

    int findSecondMinimumValue(TreeNode *root)
    {
        if (nullptr == root)
            return -1;
        int l = dfs(root->left, root->val);
        int r = dfs(root->right, root->val);
        if (-1 == l && -1 == r)
            return -1;
        else if (-1 == l)
            return r;
        else if (-1 == r)
            return l;
        return min(l, r);
        // dfs(root);
        // return min2;
    }
    int dfs(TreeNode *root, int val)
    {
        if (nullptr == root)
            return -1;
        if (val < root->val)
            return root->val;
        int l = dfs(root->left, root->val);
        int r = dfs(root->right, root->val);
        if (-1 == l && -1 == r)
            return -1;
        else if (-1 == l)
            return r;
        else if (-1 == r)
            return l;
        return min(l, r);
    }
};
// @lc code=end

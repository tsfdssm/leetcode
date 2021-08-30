/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
    string res = string(1, 'z' + 1);
    string tmp;
    void dfs(TreeNode *root)
    {
        if (nullptr == root)
        {
            return;
        }
        tmp.push_back('a' + root->val);
        if (nullptr != root->left && nullptr != root->right)
        {
            dfs(root->left);
            dfs(root->right);
        }
        else if (nullptr != root->left)
            dfs(root->left);
        else if (nullptr != root->right)
            dfs(root->right);
        else
        {
            reverse(tmp.begin(), tmp.end());
            res = min(res, tmp);
            reverse(tmp.begin(), tmp.end());
        }
        tmp.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root);
        return res;
        // if (nullptr == root)
        //     return "";
        // string res;
        // res.push_back('a' + root->val);
        // string l = dfs(root->left);
        // string r = dfs(root->right);
        // if (nullptr != root->left && nullptr != root->right)
        // {
        //     l = l + res;
        //     r = r + res;
        //     if (l < r)
        //         return l;
        //     else
        //         return r;
        // }
        // else if (nullptr != root->left)
        // {
        //     return l + res;
        // }
        // else if (nullptr != root->right)
        // {
        //     return r + res;
        // }
        // else
        // {
        //     return res;
        // }
    }
};
// @lc code=end

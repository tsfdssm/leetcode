/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode *root)
    {

        if (nullptr == root)
            return true;
        int last = 0;
        int maxn = 0x3f3f3f3f;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto [p, idx] = q.front();
                q.pop();
                if (idx >= maxn)
                    return false;
                if (nullptr != p->left)
                {
                    q.push({p->left, idx * 2});
                }
                else
                {
                    maxn = min(maxn, idx * 2);
                }
                if (nullptr != p->right)
                {
                    q.push({p->right, idx * 2 + 1});
                }
                else
                {
                    maxn = min(maxn, idx * 2 + 1);
                }
            }
        }
        return true;
    }
};
// @lc code=end

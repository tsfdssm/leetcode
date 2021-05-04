/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root)
    {

        vector<int> res;
        if (nullptr == root)
            return res;
        TreeNode *next = root;
        queue<TreeNode *> q;
        q.push(next);
        while (false == q.empty())
        {
            int n = q.size();
            TreeNode *tmp = nullptr;
            for (int i = 0; i < n; ++i)
            {
                tmp = q.front();
                q.pop();
                if (i == n - 1)
                    res.push_back(tmp->val);
                if (nullptr != tmp->left)
                    q.push(tmp->left);
                if (nullptr != tmp->right)
                    q.push(tmp->right);
            }
        }
        return res;
    }
};
// @lc code=end

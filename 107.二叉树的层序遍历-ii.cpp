/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (nullptr == root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (false == q.empty())
        {
            int cur = q.size();
            res.emplace_back(vector<int>(cur));
            for (int i = 0; i < cur; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                res.back()[i] = tmp->val;
                if (nullptr != tmp->left)
                    q.push(tmp->left);
                if (nullptr != tmp->right)
                    q.push(tmp->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (1 == depth)
        {
            TreeNode *cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        int d = 2;
        while (!q.empty())
        {
            int len = q.size();
            if (d == depth)
            {
                for (int i = 0; i < len; ++i)
                {
                    const auto cur = q.front();
                    q.pop();
                    TreeNode *l = new TreeNode(val);
                    TreeNode *r = new TreeNode(val);
                    l->left = cur->left;
                    r->right = cur->right;
                    cur->left = l;
                    cur->right = r;
                }
                break;
            }
            for (int i = 0; i < len; ++i)
            {
                const auto cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ++d;
        }
        return root;
    }
};
// @lc code=end

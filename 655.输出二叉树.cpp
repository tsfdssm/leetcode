/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(vector<vector<string>> &res, TreeNode *root, int i, int l, int r)
    {
        if (nullptr == root)
            return;
        res[i][(l + r) / 2] = to_string(root->val);
        fill(res, root->left, i + 1, l, (l + r) / 2);
        fill(res, root->right, i + 1, (l + r + 1) / 2, r);
    }
    vector<vector<string>> printTree(TreeNode *root)
    {
        int h = getHeight(root);
        vector<vector<string>> res(h, vector<string>((1 << h) - 1, ""));
        fill(res, root, 0, 0, res[0].size());
        return res;
        // vector<vector<string>> res;
        // if (nullptr == root)
        //     return res;
        // auto l = printTree(root->left);
        // auto r = printTree(root->right);
        // int m_child = max(l.size(), r.size());
        // if (0 == m_child)
        // {
        //     res.resize(1, vector<string>(1, to_string(root->val)));
        //     return res;
        // }
        // int n_child = 0;
        // if (l.size() > 0)
        //     n_child = l[0].size();
        // if (r.size() > 0)
        //     n_child = max((int)r[0].size(), n_child)'';
        // l.resize(m_child, vector<string>(n_child));
        // r.resize(m_child, vector<string>(n_child));
        // res.resize(1, vector<string>(2 * n_child + 1));
        // res[0][n_child + 1] = to_string(root->val);
        // for (int i = 0; i < m_child; ++i)
        // {
        //     auto &tmp = res.back();
        //     res.emplace_back(l[i]);
        //     tmp.push_back("");
        //     tmp.insert(tmp.end(), r[i].begin(), r[i].end());
        // }
        // return res;
    }
};
// @lc code=end

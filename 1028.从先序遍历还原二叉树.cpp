/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
    TreeNode *recoverFromPreorder(string traversal)
    {
        stack<TreeNode *> path;
        int pos = 0;
        int n = traversal.size();
        while (pos < n)
        {
            int level = 0;
            while (traversal[pos] == '-')
            {
                ++level;
                ++pos;
            }
            int value = 0;
            while (pos < n && isdigit(traversal[pos]))
            {
                value = value * 10 + (traversal[pos] - '0');
                ++pos;
            }
            TreeNode *node = new TreeNode(value);
            if (level == path.size())
            {
                if (!path.empty())
                    path.top()->left = node;
            }
            else
            {
                while (level != path.size())
                    path.pop();
                path.top()->right = node;
            }
            path.push(node);
        }

        while (path.size() > 1)
        {
            path.pop();
        }
        return path.top();
    }
};
// @lc code=end

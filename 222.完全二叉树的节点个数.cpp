/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        int level = 0;
        TreeNode *node = root;
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        int low = 1 << level;
        int high = (1 << (level + 1)) - 1;

        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;

        // if (nullptr == root)
        //     return 0;
        // return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool exists(TreeNode *root, int level, int k)
    {
        int bit = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bit > 0)
        {
            if (bit & k)
                node = node->right;
            else
                node = node->left;
            bit >>= 1;
        }
        return node != nullptr;
    }
};
// @lc code=end

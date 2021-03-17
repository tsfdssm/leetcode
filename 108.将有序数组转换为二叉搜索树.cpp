/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *ArrayConstruct(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return nullptr;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = ArrayConstruct(nums, l, mid);
        root->right = ArrayConstruct(nums, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return ArrayConstruct(nums, 0, nums.size());
    }
};
// @lc code=end

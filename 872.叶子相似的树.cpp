/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1;
        vector<int> v2;
        function<void(TreeNode *, vector<int> &)> dfs = [&](TreeNode *root, vector<int> &vec) {
            if (nullptr == root)
                return;
            if (nullptr == root->left && nullptr == root->right)
            {
                vec.emplace_back(root->val);
                return;
            }
            dfs(root->left, vec);
            dfs(root->right, vec);
        };
        dfs(root1, v1);
        dfs(root2, v2);
        return v1 == v2;
    }
};
// @lc code=end

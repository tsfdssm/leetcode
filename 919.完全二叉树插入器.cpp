/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter
{
public:
    unordered_map<int, TreeNode *> mp;
    CBTInserter(TreeNode *root)
    {
        dfs(root, 1);
    }
    void dfs(TreeNode *root, int idx)
    {
        if (nullptr == root)
            return;
        mp[idx] = root;
        dfs(root->left, idx * 2);
        dfs(root->right, idx * 2 + 1);
    }

    int insert(int val)
    {
        TreeNode *root = new TreeNode(val);
        int idx = mp.size() + 1;
        mp[idx] = root;
        if (idx % 2 == 0)
        {
            mp[idx / 2]->left = root;
        }
        else
        {
            mp[idx / 2]->right = root;
        }
        return mp[idx / 2]->val;
    }

    TreeNode *get_root()
    {
        return mp[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

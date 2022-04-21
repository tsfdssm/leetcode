/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 *
 * https://leetcode-cn.com/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (63.60%)
 * Likes:    171
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 22.4K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * 给出二叉树的根节点 root，树上每个节点都有一个不同的值。
 *
 * 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
 *
 * 返回森林中的每棵树。你可以按任意顺序组织答案。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * 输出：[[1,2,null,4],[6],[7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,4,null,3], to_delete = [3]
 * 输出：[[1,2,4]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数最大为 1000。
 * 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
 * to_delete.length <= 1000
 * to_delete 包含一些从 1 到 1000、各不相同的值。
 *
 *
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
    vector<TreeNode *> res;
    void solve(TreeNode *root, set<int> &st, bool flag)
    {
        if (!st.count(root->val) && flag)
            res.emplace_back(root);
        flag = st.count(root->val);
        if (nullptr != root->left)
        {
            solve(root->left, st, flag);
            if (st.count(root->left->val))
                root->left = nullptr;
        }
        if (nullptr != root->right)
        {
            solve(root->right, st, flag);
            if (st.count(root->right->val))
                root->right = nullptr;
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (nullptr == root)
            return {};
        set<int> st(to_delete.begin(), to_delete.end());
        solve(root, st, true);
        return res;
    }
};
// @lc code=end

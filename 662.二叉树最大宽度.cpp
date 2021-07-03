/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        deque<pair<TreeNode *, int>> q{{root, 1}};
        int res = 0;
        while (!q.empty())
        {
            int len = q.size();
            res = max(res, q.back().second - q.front().second + 1);
            int offset = q.front().second;
            for (int i = 0; i < len; ++i)
            {
                auto [cur, pos] = q.front();
                pos -= offset;
                q.pop_front();
                if (cur->left)
                    q.push_back({cur->left, pos * 2});
                if (cur->right)
                    q.push_back({cur->right, pos * 2 + 1});
            }
        }
        return res;
        // if (nullptr == root)
        //     return 0;
        // queue<TreeNode *> q;
        // q.push(root);
        // int res = 1;
        // while (!q.empty())
        // {
        //     int len = q.size();
        //     bool s = false;
        //     int ed = 0;
        //     int cnt = 0;
        //     for (int i = 0; i < len; ++i)
        //     {
        //         auto cur = q.front();
        //         if (nullptr == cur)
        //         {
        //             q.push(nullptr);
        //             q.push(nullptr);
        //         }
        //         else
        //         {
        //             if (nullptr != cur->left)
        //             {
        //                 q.push(cur->left);
        //                 s = true;
        //                 cnt++;
        //                 ed = cnt;
        //             }
        //             else
        //             {
        //                 if (s)
        //                     cnt++;
        //                 q.push(nullptr);
        //             }
        //             if (nullptr != cur->right)
        //             {
        //                 q.push(cur->right);
        //                 s = true;
        //                 cnt++;
        //                 ed = cnt;
        //             }
        //             else
        //             {
        //                 if (s)
        //                     cnt++;
        //                 q.push(nullptr);
        //             }
        //         }

        //         q.pop();
        //     }
        //     res = max(res, ed);
        // }
        // return res;
    }
};
// @lc code=end

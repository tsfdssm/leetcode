/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getL(ListNode *root)
    {
        int i = 0;
        while (nullptr != root)
        {
            root = root->next;
            i++;
        }
        return i;
    }
    TreeNode *inorder(ListNode *&head, int l, int r)
    {
        if (l >= r)
            return nullptr;
        int mid = (r + l) / 2;
        TreeNode *root = new TreeNode();
        root->left = inorder(head, l, mid);
        root->val = head->val;
        head = head->next;
        root->right = inorder(head, mid + 1, r);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        return inorder(head, 0, getL(head));
    }
};
// @lc code=end

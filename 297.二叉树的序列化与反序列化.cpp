/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (nullptr == root)
            return "X";
        auto l = "(" + serialize(root->left) + ")";
        auto r = "(" + serialize(root->right) + ")";
        return l + to_string(root->val) + r;
    }

    inline TreeNode *parseSubTree(string &data, int &ptr)
    {
        ptr++;
        auto subTree = parse(data, ptr);
        ptr++;
        return subTree;
    }

    inline int parseInt(string &data, int &ptr)
    {
        int x = 0;
        int sgn = 1;
        if ('-' == data[ptr])
        {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr]))
        {
            x *= 10;
            x += data[ptr++] - '0';
        }
        return sgn * x;
    }

    TreeNode *parse(string &data, int &ptr)
    {
        if ('X' == data[ptr])
        {
            ++ptr;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubTree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubTree(data, ptr);
        return cur;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int ptr = 0;
        return parse(data, ptr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

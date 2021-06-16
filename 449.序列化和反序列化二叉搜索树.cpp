/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
            return "";
        stringstream ss;
        preSerial(root, ss);
        return ss.str();
    }
    void preSerial(TreeNode *root, stringstream &ss)
    {
        if (nullptr == root)
        {
            ss << "# ";
            return;
        }
        ss << to_string(root->val) + " ";
        preSerial(root->left, ss);
        preSerial(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (0 == data.size())
            return nullptr;
        TreeNode *root = nullptr;
        stringstream ss(data);
        rebuild(root, ss);
        return root;
    }

    void rebuild(TreeNode *&root, stringstream &ss)
    {
        string t;
        ss >> t;
        if (t[0] == '#')
        {
            root = nullptr;
            return;
        }
        root = new TreeNode(stoi(t));
        rebuild(root->left, ss);
        rebuild(root->right, ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

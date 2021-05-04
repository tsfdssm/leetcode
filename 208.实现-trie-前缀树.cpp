/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
    vector<Trie *> children;
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false)
    {
    }

    Trie *prefix(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
            {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
    /** Inserts a word into the trie. */
    void insert(const string &word)
    {
        Trie *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
            {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word)
    {
        Trie *node = prefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix)
    {
        return this->prefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

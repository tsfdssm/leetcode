/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
class Trie
{
public:
    vector<Trie *> children = vector<Trie *>(26, nullptr);
    int ed = 0;
    void insert(const string &s)
    {
        Trie *cur = this;
        for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        {
            char c = *rit;
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new Trie();
            }

            cur->ed = 2;
            cur = cur->children[c - 'a'];
        }
        if (cur->ed == 0)
            cur->ed = 1;
    }

    Trie *find(const string &s)
    {
        Trie *cur = this;
        for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        {
            char c = *rit;
            if (cur->children[c - 'a'] == nullptr)
            {
                return nullptr;
            }
            cur = cur->children[c - 'a'];
        }
        return cur;
    }
};
class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie *tree = new Trie();
        set<string> tmp = set<string>(words.begin(), words.end());
        words = vector<string>(tmp.begin(), tmp.end());
        for (string &word : words)
            tree->insert(word);
        int res = 0;
        for (string &word : words)
            if (1 == tree->find(word)->ed)
                res += word.size() + 1;
        return res;
    }
};
// @lc code=end

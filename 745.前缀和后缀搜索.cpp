/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
class Trie
{
public:
    int ed = -1;
    vector<Trie *> nxt = vector<Trie *>(27, nullptr);

    void insert(const string &s, int id)
    {
        Trie *cur = this;
        for (char c : s)
        {
            int idx = -1;
            if ('#' == c)
                idx = 26;
            else
                idx = c - 'a';
            if (nullptr == cur->nxt[idx])
                cur->nxt[idx] = new Trie();
            cur->ed = id;
            cur = cur->nxt[idx];
        }
        cur->ed = id;
    }

    int find(const string &prefix)
    {
        Trie *cur = this;
        for (char c : prefix)
        {
            int idx = -1;
            if ('#' == c)
                idx = 26;
            else
                idx = c - 'a';
            if (nullptr == cur->nxt[idx])
                return -1;
            cur = cur->nxt[idx];
        }
        return cur->ed;
    }
};
class WordFilter
{
public:
    const vector<string> &vec;
    Trie tree;
    WordFilter(const vector<string> &words) : vec(words)
    {

        for (int i = 0; i < words.size(); ++i)
        {
            tree.insert("#" + words[i], i);
            for (int j = 0; j < words[i].size(); ++j)
                tree.insert(words[i].substr(j) + "#" + words[i], i);
        }
    }

    int f(const string &prefix, const string &suffix)
    {
        return tree.find(suffix + "#" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

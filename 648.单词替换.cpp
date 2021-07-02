/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
struct Trie
{
    bool ed = false;
    vector<Trie *> nxt;
    Trie()
    {
        ed = false;
        nxt.resize(26, nullptr);
    }
    string prefix(const string &s)
    {
        Trie *cur = this;
        string prefix;
        for (char c : s)
        {
            if (true == cur->ed)
                break;
            prefix += c;
            if (nullptr == cur->nxt[c - 'a'])
                return s;
            cur = cur->nxt[c - 'a'];
        }
        return prefix;
    }

    void add(const string &s)
    {
        Trie *cur = this;
        for (char c : s)
        {
            if (nullptr == cur->nxt[c - 'a'])
                cur->nxt[c - 'a'] = new Trie();
            cur = cur->nxt[c - 'a'];
        }
        cur->ed = true;
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *tree = new Trie();
        for (const string &s : dictionary)
            tree->add(s);
        int n = sentence.size();
        string res;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j < n && sentence[j] != ' ')
                ++j;
            string tmp = tree->prefix(sentence.substr(i, j - i));
            i = j;
            res += res.empty() ? tmp : " " + tmp;
        }
        delete tree;
        return res;
    }
};
// @lc code=end

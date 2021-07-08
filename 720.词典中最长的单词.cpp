/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Trie
{
public:
    bool ed = false;
    vector<Trie *> vec = vector<Trie *>(26, nullptr);

    bool check(const string &s)
    {
        auto cur = this;
        for (char c : s)
        {
            if (nullptr == cur->vec[c - 'a'])
                return false;
            cur = cur->vec[c - 'a'];
            if (!cur->ed)
                return false;
        }
        return true;
    }

    void insert(const string &s)
    {
        auto cur = this;
        for (char c : s)
        {
            if (nullptr == cur->vec[c - 'a'])
                cur->vec[c - 'a'] = new Trie();
            cur = cur->vec[c - 'a'];
        }
        cur->ed = true;
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie tree;
        for (string s : words)
            tree.insert(s);

        sort(words.begin(), words.end(), [](const auto &a, const auto &b) { return a.size() > b.size() || (a.size() == b.size() && a < b); });
        int maxL = 0;
        vector<string> res;
        for (int i = 0; i < words.size(); ++i)
        {
            if (tree.check(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
class Trie
{
public:
    bool is_string;
    Trie *next[26];
    Trie()
    {
        is_string = false;
        memset(next, 0, sizeof(next));
    }
    void insert(const string &word)
    {
        Trie *root = this;
        for (const auto &c : word)
        {
            if (nullptr == root->next[c - 'a'])
                root->next[c - 'a'] = new Trie();
            root = root->next[c - 'a'];
        }
        root->is_string = true;
    }
    bool search(const string &word, int index, int count)
    {
        Trie *root = this;
        const int n = word.size();
        for (int i = index; i < n; ++i)
        {
            if (nullptr == root->next[word[i] - 'a'])
                return false;
            root = root->next[word[i] - 'a'];
            if (root->is_string)
            {
                if (i == n - 1)
                    return count >= 1;
                if (search(word, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }
};
class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie *root = new Trie();
        for (const auto &word : words)
            root->insert(word);
        vector<string> res;
        for (const auto &word : words)
            if (root->search(word, 0, 0))
                res.emplace_back(word);
        return res;
    }
};
// @lc code=end

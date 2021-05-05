/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Trie
{
public:
    vector<Trie *> children;
    bool isEnd;
    Trie() : children(26), isEnd(false)
    {
    }
    Trie *prefix(const string &word)
    {
        Trie *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (nullptr == node->children[c])
                return nullptr;
            node = node->children[c];
        }
        return node;
    }
    void insert(const string &word)
    {
        Trie *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (nullptr == node->children[c])
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    int find(const string &word)
    {
        Trie *node = prefix(word);
        if (nullptr == node)
            return 0;
        else if (false == node->isEnd)
            return 1;
        else
            return 2;
    }
};
class Solution
{
public:
    unordered_set<string> res;
    string tmp;
    vector<vector<bool>> vis;
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        if (0 == board.size() || 0 == board[0].size())
            return {};
        int m = board.size();
        int n = board[0].size();
        Trie dict;
        vis.resize(m, vector<bool>(n, false));
        for (const string &word : words)
            dict.insert(word);
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, dict, i, j);
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>> &board, Trie &dict, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || m <= i || j < 0 || n <= j)
            return;
        if (vis[i][j])
            return;
        tmp.push_back(board[i][j]);
        vis[i][j] = true;
        int req = dict.find(tmp);
        if (0 != req)
        {
            if (2 == req)
            {
                res.insert(tmp);
            }
            dfs(board, dict, i + 1, j);
            dfs(board, dict, i - 1, j);
            dfs(board, dict, i, j + 1);
            dfs(board, dict, i, j - 1);
        }
        tmp.pop_back();
        vis[i][j] = false;
    }
};

// @lc code=end

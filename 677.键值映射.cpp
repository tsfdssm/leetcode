/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class Trie
{
public:
    bool ed = false;
    int val = 0;
    vector<Trie *> nxt = vector<Trie *>(26, nullptr);
    int sum(const string &prefix)
    {
        Trie *cur = this;
        for (char c : prefix)
        {
            if (nullptr == cur->nxt[c - 'a'])
                return 0;
            cur = cur->nxt[c - 'a'];
        }
        return cur->sumAll();
    }

    int sumAll()
    {
        int res = this->val;
        for (auto it : nxt)
        {
            if (nullptr != it)
                res += it->sumAll();
        }
        return res;
    }
    void insert(const string &s, int val)
    {
        Trie *cur = this;
        for (char c : s)
        {
            if (nullptr == cur->nxt[c - 'a'])
                cur->nxt[c - 'a'] = new Trie();
            cur = cur->nxt[c - 'a'];
        }
        cur->ed = true;
        cur->val = val;
    }
};
class MapSum
{
public:
    /** Initialize your data structure here. */
    Trie tree;
    MapSum()
    {
    }

    void insert(const string &key, int val)
    {
        tree.insert(key, val);
    }

    int sum(const string &prefix)
    {
        return tree.sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

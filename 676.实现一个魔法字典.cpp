/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class MagicDictionary
{
public:
    /** Initialize your data structure here. */

    unordered_map<string, unordered_set<string>> mp;
    MagicDictionary()
    {
    }

    void buildDict(const vector<string> &dictionary)
    {
        string tmp;
        for (const auto &s : dictionary)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                tmp = s;
                tmp[i] = '*';
                mp[tmp].emplace(s);
            }
        }
    }

    bool search(const string &searchWord)
    {
        string tmp;
        for (int i = 0; i < searchWord.size(); ++i)
        {
            tmp = searchWord;
            tmp[i] = '*';
            if (mp.count(tmp) && (mp[tmp].size() > 1 || mp[tmp].size() == 1 && !mp[tmp].count(searchWord)))
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

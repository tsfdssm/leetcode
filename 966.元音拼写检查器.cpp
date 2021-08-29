/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
 */

// @lc code=start
class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        set<string> org;
        map<string, int> less;
        map<string, int> mp;
        int n = wordlist.size();
        for (int i = 0; i < n; ++i)
        {
            string &s = wordlist[i];
            org.insert(s);
            string s2 = s;
            for (int j = 0; j < s2.size(); ++j)
                if (upChar(s2[j]))
                    s2[j] += 'a' - 'A';
            if (!less.count(s2))
                less[s2] = i;
            for (int j = 0; j < s2.size(); ++j)
            {
                if (isA(s2[j]))
                    s2[j] = '-';
            }
            if (!mp.count(s2))
                mp[s2] = i;
        }
        vector<string> res(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            string &s = queries[i];
            if (org.count(s))
            {
                res[i] = s;
            }
            else
            {
                string s2 = s;
                for (int j = 0; j < s2.size(); ++j)
                    if (upChar(s2[j]))
                        s2[j] += 'a' - 'A';
                if (less.count(s2))
                    res[i] = wordlist[less[s2]];
                else
                {
                    for (int j = 0; j < s2.size(); ++j)
                    {
                        if (isA(s2[j]))
                            s2[j] = '-';
                    }
                    if (mp.count(s2))
                        res[i] = wordlist[mp[s2]];
                    else
                        res[i] = "";
                }
            }
        }
        return res;
    }
    inline bool isA(char c)
    {
        return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c;
    }

    inline bool upChar(char c)
    {
        return 'A' <= c && c <= 'Z';
    }
};
// @lc code=end

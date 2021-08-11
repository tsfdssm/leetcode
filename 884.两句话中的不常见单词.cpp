/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution
{
public:
    map<string, int> getWord(const string &s)
    {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1;
            while (j < n && s[j] != ' ')
                ++j;
            mp[s.substr(i, j - i)]++;
            i = j;
        }
        return mp;
    }
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> mp1 = getWord(s1);
        map<string, int> mp2 = getWord(s2);
        vector<string> res;
        for (auto it : mp1)
        {
            if (it.second > 1)
                continue;
            if (!mp2.count(it.first))
                res.emplace_back(it.first);
        }
        for (auto it : mp2)
        {
            if (it.second > 1)
                continue;
            if (!mp1.count(it.first))
                res.emplace_back(it.first);
        }
        return res;
    }
};
// @lc code=end

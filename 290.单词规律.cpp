/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include <set>
#include <map>
#include <multiset>
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        int st = 0;
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (st >= s.size())
                return false;
            while (st < s.size() && s[st] == ' ')
                ++st;
            int ed = st;
            while (ed < s.size() && s[ed] != ' ')
                ++ed;
            const string &tmp = s.substr(st, ed - st);
            st = ed;
            char c = pattern[i];
            if (mp.count(c) && mp[c] != tmp)
                return false;

            if (mp2.count(tmp) && mp2[tmp] != c)
                return false;
            mp[c] = tmp;
            mp2[tmp] = c;
        }
        return st >= s.size();
    }
};
// @lc code=end

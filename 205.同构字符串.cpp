/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> hash;
        unordered_map<char, char> hash2;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((0 == hash.count(s[i])) && (0 == hash2.count(t[i])))
            {
                hash[s[i]] = t[i];
                hash2[t[i]] = s[i];
            }
            else if (hash[s[i]] != t[i] || hash2[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

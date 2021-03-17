/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        int n = s1.size();
        int ch[26] = {0};
        for (int i = 0; i < n; i++)
        {
            ch[s1[i] - 'a']++;
            ch[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (ch[i] != 0)
                return false;
        for (int i = 1; i < s1.size(); i++)
        {

            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            else if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};
// @lc code=end

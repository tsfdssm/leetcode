/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution
{
public:
    string toGoatLatin(string s)
    {
        string res;
        int n = s.size();
        int cnt = 1;
        for (int i = 0; i < n; ++i)
        {
            if (' ' == s[i])
                continue;
            int j = i + 1;
            while (j < n && isChar(s[j]))
                ++j;
            string tmp;
            if (isA(s[i]))
            {
                tmp = s.substr(i, j - i) + "ma";
            }
            else
            {
                tmp = s.substr(i + 1, j - i - 1) + s[i] + "ma";
            }
            tmp += string(cnt, 'a');
            if (j < n)
                tmp += ' ';
            res += tmp;
            i = j;
            ++cnt;
        }
        return res;
    }

    inline bool isChar(char c)
    {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
    }

    inline bool isA(char c)
    {
        if ('A' <= c && c <= 'Z')
            c += 'a' - 'A';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
// @lc code=end

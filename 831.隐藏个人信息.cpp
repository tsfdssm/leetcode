/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution
{
public:
    string maskPII(const string &s)
    {
        if (isChar(s[0]))
            return maskMail(s);
        return maskPhone(s);
    }

    string maskMail(const string &s)
    {
        int n = s.size();
        string res;
        res += s[0];
        res += "*****";
        int idx = 0;
        while (s[idx] != '@')
            ++idx;
        res += s.substr(idx - 1);
        for (int i = 0; i < res.size(); ++i)
            if ('A' <= res[i] && res[i] <= 'Z')
                res[i] += 'a' - 'A';
        return res;
    }

    string maskPhone(const string &s)
    {
        string res;
        int cnt = 0;
        for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        {
            char c = *rit;
            if (isDigit(c))
            {
                if (cnt == 4 || cnt == 7 || cnt == 10)
                    res += '-';
                ++cnt;
                if (cnt <= 4)
                {
                    res += c;
                }
                else
                    res += '*';
            }
            else
            {
            }
        }
        if (cnt > 10)
            res += '+';
        reverse(res.begin(), res.end());
        return res;
    }

    inline bool isChar(char c)
    {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
    }

    inline bool isDigit(char c)
    {
        return '0' <= c && c <= '9';
    }
};
// @lc code=end

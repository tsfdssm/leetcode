/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        s = solve(s);
        t = solve(t);
        return s == t;
    }

    string solve(const string &s)
    {
        int n = s.size();
        string res;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '#')
            {
                if (!res.empty())
                    res.pop_back();
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        int idx = 0;
        int n = s.size();
        int cntl = 0;
        int cntr = 0;
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if ('(' == c)
                ++cntl;
            else
                ++cntr;
            if (cntl == cntr)
            {
                res += s.substr(idx + 1, i - idx - 1);
                idx = i + 1;
            }
                }
        return res;
    }
};
// @lc code=end

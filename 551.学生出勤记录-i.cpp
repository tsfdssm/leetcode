/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int na = 0;
        int nl = 0;
        int conl = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if ('A' == c)
            {
                ++na;
                nl = 0;
            }
            else if ('L' == c)
            {
                ++nl;
                conl = max(conl, nl);
            }
            else
            {
                nl = 0;
            }
        }
        return na <= 1 && conl <= 2;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=972 lang=cpp
 *
 * [972] 相等的有理数
 */

// @lc code=start
class Solution
{
public:
    bool isRationalEqual(string s, string t)
    {
        return fabs(decimal(s) - decimal(t)) < 1e-8;
    }
    double decimal(string s)
    {
        int l = s.find('('), r = s.find(')');
        if (l != -1 && r != -1)
        {
            string X = s.substr(0, l), Y = s.substr(l + 1, r - l - 1);
            string XY = X + Y + Y + Y + Y + Y + Y + Y + Y + Y;
            return atof(XY.c_str());
        }
        else
            return atof(s.c_str());
    }
};
// @lc code=end

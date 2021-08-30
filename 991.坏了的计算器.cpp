/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution
{
public:
    int brokenCalc(int x, int y)
    {
        int res = 0;
        while (x < y)
        {
            ++res;
            if (y & 1)
            {
                ++y;
            }
            else
            {
                y /= 2;
            }
        }
        return res + x - y;
    }
};
// @lc code=end

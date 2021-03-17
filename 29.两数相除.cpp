/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (0 == divisor)
            return 0;
        if (1 == divisor)
            return dividend;
        if (-1 == divisor)
        {
            if (INT_MIN != dividend)
                return -dividend;
            return INT_MAX;
        }

        long a = dividend, b = divisor;
        bool flag = true;
        if (a < 0 && b > 0 || a > 0 && b < 0)
            flag = false;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        int res = div(a, b);
        if (!flag)
            return -res;
        return res;
    }

    int div(long a, long b)
    {
        if (a < b)
            return 0;
        long count = 1;
        long b0 = b;
        while (b + b < a)
        {
            count += count;
            b += b;
        }
        return count + div(a - b, b0);
    }
};
// @lc code=end

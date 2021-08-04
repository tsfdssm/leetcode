/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        while ((n & 1) == 0)
            n >>= 1;
        int res = 1;
        int d = 3;
        while (d * d <= n)
        {
            int e = 0;
            while (n % d == 0)
            {
                n /= d;
                ++e;
            }
            res *= e + 1;
            d += 2;
        }
        if (n > 1)
            res <<= 1;
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double quikPow(double x, long long n)
    {
        double res = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1)
                res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        return N > 0 ? quikPow(x, N) : 1.0 / quikPow(x, -N);
    }
};
// @lc code=end

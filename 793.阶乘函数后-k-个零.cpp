/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution
{
public:
    long long cnt(long long x)
    {
        if (x == 0)
            return 0;
        return x / 5 + cnt(x / 5);
    }
    int preimageSizeFZF(int k)
    {
        long long l = k, r = 10 * (long)k + 1;
        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            long long num = cnt(mid);
            if (num == k)
                return 5;
            else if (num > k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

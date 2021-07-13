/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int res = 0;
        for (int i = left; i <= right; ++i)
        {
            if (isPrime(count(i)))
                ++res;
        }
        return res;
    }
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        if (2 == x)
            return true;
        for (int i = 2; i * i <= x; ++i)
            if (x % i == 0)
                return false;
        return true;
    }

    int count(int x)
    {
        int cnt = 0;
        while (x > 0)
        {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        long long prefix = 1;
        long long p = 1;
        while (p < k)
        {
            long long cnt = getCount(prefix, n);
            if (p + cnt > k)
            {
                prefix *= 10;
                p++;
            }
            else
            {
                prefix++;
                p += cnt;
            }
        }
        return prefix;
    }
    long long getCount(long long prefix, long long n)
    {
        long long cnt = 0;
        for (long long a = prefix, b = prefix + 1; a <= n; a *= 10, b *= 10)
            cnt += min(n + 1, b) - a;
        return cnt;
    }
};
// @lc code=end

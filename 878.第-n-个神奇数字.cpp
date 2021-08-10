/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        const int mod = 1e9 + 7;
        if (a > b)
            swap(a, b);
        if (a == b || (b % a == 0))
            return (long long)n * a % mod;
        int len = (a * b) / gcd(a, b);
        int cycle = len / a + len / b - 1;
        long long cnt = n / cycle;
        long long pos = n % cycle;
        cnt *= len;
        cnt %= mod;
        if (0 == pos)
            return cnt;
        auto int l = min(a, b), r = len;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if ((mid / a + mid / b) >= pos)
                r = mid;
            else
                l = mid + 1;
        }
        cnt += l;
        cnt %= mod;
        return cnt;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
// @lc code=end

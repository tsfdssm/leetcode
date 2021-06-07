/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution
{
public:
    int findNthDigit(int t)
    {
        long long n = t;
        if (n <= 9)
            return n;

        int k = 1;
        long long st = 1;
        long long cnt = 9 * k * st;
        while (cnt < n)
        {
            n -= cnt;
            st *= 10;
            ++k;
            cnt = 9 * k * st;
        }
        int num = st + (n - 1) / k;
        int remainder = (n - 1) % k;

        string res = to_string(num);
        return (int)(res[remainder] - '0');
    }
};
// @lc code=end

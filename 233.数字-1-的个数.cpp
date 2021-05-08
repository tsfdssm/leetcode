/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int countDigitOne(int n)
    {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            long long div = i * 10;
            cnt += (n / div) * i + min(max(n % div - i + 1, 0ll), i);
        }
        return cnt;
    }
};
// @lc code=end

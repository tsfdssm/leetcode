/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> dp(32, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 32; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        int sum = 0;
        int i = 31;
        int prev = 0;
        while (i >= 0)
        {
            if (n & (1 << i))
            {
                sum += dp[i];
                if (1 == prev)
                {
                    sum--;
                    break;
                }
                prev = 1;
            }
            else
                prev = 0;
            --i;
        }
        return sum + 1;
    }
};
// @lc code=end

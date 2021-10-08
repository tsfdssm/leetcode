/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
class Solution
{
public:
    bool divisorGame(int n)
    {
        if (n < 2)
            return false;
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int k = 1; k * k <= i; ++k)
            {
                if (i % k == 0)
                {
                    if (0 == dp[i - k])
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

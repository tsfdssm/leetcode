/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int k = 2; i * k <= n; ++k)
                dp[i * k] = min(dp[i * k], dp[i] + k);
        }
        return dp[n];
    }
};
// @lc code=end

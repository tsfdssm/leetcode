/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

// @lc code=start
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
            {
                if (j >= i)
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                if (dp[i][j] < 0)
                    dp[i][j] += mod;
                dp[i][j] %= mod;
            }
        return (int)dp[n][k] % mod;
    }
};
// @lc code=end

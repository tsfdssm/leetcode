/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int m = amount + 1;
        vector<int> dp(m, m);
        dp[0] = 0;
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i >= coins[j])
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        return m == dp.back() ? -1 : dp.back();
    }
};
// @lc code=end

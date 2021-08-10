/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int m = group.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            int need = group[i - 1];
            int earn = profit[i - 1];
            for (int j = n; j >= 0; --j)
                for (int k = minProfit; k >= 0; --k)
                {
                    if (j >= need)
                        dp[j][k] = (dp[j][k] + dp[j - need][max(0, k - earn)]) % mod;
                }
        }
        int sum = 0;
        for (int j = 0; j <= n; ++j)
            sum = (sum + dp[j][minProfit]) % mod;
        return sum;
        // int m = group.size();
        // const int mod = 1e9 + 7;
        // vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        // dp[0][0][0] = 1;
        // for (int i = 1; i <= m; ++i)
        // {
        //     int need = group[i - 1];
        //     int earn = profit[i - 1];
        //     for (int j = 0; j <= n; ++j)
        //         for (int k = 0; k <= minProfit; ++k)
        //         {
        //             if (j < need)
        //                 dp[i][j][k] = dp[i - 1][j][k];
        //             else
        //                 dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - need][max(0, k - earn)]) % mod;
        //         }
        // }
        // int sum = 0;
        // for (int j = 0; j <= n; ++j)
        //     sum = (sum + dp[m][j][minProfit]) % mod;
        // return sum;
    }
};
// @lc code=end

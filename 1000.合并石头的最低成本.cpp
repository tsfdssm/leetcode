/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start

class Solution
{
public:
    using VI = vector<int>;
    using VII = vector<VI>;
    using VIII = vector<VII>;
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;
        const int inf = 0x3f3f3f3f;
        VIII dp(n + 1, VII(n + 1, VI(k + 1, inf)));
        VI sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + stones[i - 1];
        for (int i = 0; i <= n; ++i)
            dp[i][i][1] = 0;
        for (int len = 2; len <= n; ++len)
            for (int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                for (int m = 2; m <= k; ++m)
                    for (int p = i; p < j; p += k - 1)
                        dp[i][j][m] = min(dp[i][j][m], dp[i][p][1] + dp[p + 1][j][m - 1]);
                dp[i][j][1] = dp[i][j][k] + sum[j] - sum[i - 1];
            }
        return dp[1][n][1];
    }
};
// @lc code=end

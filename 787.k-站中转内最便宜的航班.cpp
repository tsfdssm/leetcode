/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> adj(n, vector<int>(n, inf));
        vector<vector<int>> dp(n, vector<int>(k + 1, inf));

        for (auto e : flights)
        {
            adj[e[0]][e[1]] = e[2];
        }

        dp[src][0] = 0;
        for (int u = 0; u < n; ++u)
        {
            if (adj[src][u] == inf)
                continue;
            dp[u][0] = adj[src][u];
        }
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp[j][i] == inf)
                    continue;
                dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
                for (int v = 0; v < n; ++v)
                {
                    if (adj[j][v] == inf)
                        continue;
                    dp[v][i + 1] = min(dp[v][i + 1], dp[j][i] + adj[j][v]);
                }
            }
        }
        if (dp[dst][k] == inf)
            return -1;
        return dp[dst][k];
    }
};
// @lc code=end

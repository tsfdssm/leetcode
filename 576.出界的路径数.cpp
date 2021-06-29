/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        const int mod = 1e9 + 7;
        if (maxMove <= 0)
            return 0;
        vector<vector<vector<long>>> dp(maxMove, vector<vector<long>>(m, vector<long>(n, 0)));
        for (int i = 0; i < maxMove; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i][m - 1][j]++;
                dp[i][0][j]++;
            }
            for (int j = 0; j < m; ++j)
            {
                dp[i][j][0]++;
                dp[i][j][n - 1]++;
            }
            if (i)
                for (int j = 0; j < m; ++j)
                    for (int k = 0; k < n; ++k)
                        for (int t = 0; t < 4; ++t)
                        {
                            int tj = j + dir_x[t];
                            int tk = k + dir_y[t];
                            if (tj < 0 || tj >= m || tk < 0 || tk >= n)
                                continue;
                            dp[i][j][k] += dp[i - 1][tj][tk];
                            dp[i][j][k] %= mod;
                        }
        }
        return dp[maxMove - 1][startRow][startColumn];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

// @lc code=start
class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        int dir_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dir_y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
        dp[row][column] = 1.0;
        for (; k > 0; --k)
        {
            auto nxt_dp = vector<vector<double>>(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int t = 0; t < 8; ++t)
                    {
                        int tmpi = i + dir_x[t];
                        int tmpj = j + dir_y[t];
                        if (tmpi < 0 || tmpi >= n || tmpj < 0 || tmpj >= n)
                            continue;
                        nxt_dp[tmpi][tmpj] += dp[i][j] / 8.0;
                    }
            dp = move(nxt_dp);
            //dp = nxt_dp;
        }
        double res = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res += dp[i][j];
        return res;
    }
};
// @lc code=end

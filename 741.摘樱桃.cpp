/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

// @lc code=start
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dp[n + 1][n + 1];
        memset(dp, 0x80, sizeof(dp));
        dp[n - 1][n - 1] = grid[n - 1][n - 1];
        for (int sum = 2 * n - 3; sum >= 0; --sum)
            for (int i1 = max(0, sum - n + 1); i1 <= min(sum, n - 1); i1++)
                for (int i2 = i1; i2 <= min(sum, n - 1); i2++)
                {
                    int j1 = sum - i1;
                    int j2 = sum - i2;
                    if (grid[i1][j1] == -1 || grid[i2][j2] == -1)
                        dp[i1][i2] = INT_MIN;
                    else
                        dp[i1][i2] = grid[i1][j1] + (i1 != i2 || j1 != j2) * grid[i2][j2] + max(max(dp[i1 + 1][i2], dp[i1][i2 + 1]), max(dp[i1][i2], dp[i1 + 1][i2 + 1]));
                }
        return max(0, dp[0][0]);
    }
};
// @lc code=end

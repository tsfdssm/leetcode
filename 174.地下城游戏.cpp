/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (0 == dungeon.size())
            return 0;
        if (0 == dungeon[0].size())
            return 0;
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
            {
                int mn = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(mn - dungeon[i][j], 1);
            }
        return dp[0][0];
    }
};
// @lc code=end

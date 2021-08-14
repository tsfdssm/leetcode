/*
 * @lc app=leetcode.cn id=920 lang=cpp
 *
 * [920] 播放列表的数量
 */

// @lc code=start
class Solution
{
public:
    int numMusicPlaylists(int n, int l, int k)
    {
        const int mod = 1e9 + 7;
        vector<vector<long>> dp(l + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= l; ++i)
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] * max(j - k, 0) + dp[i - 1][j - 1] * (n - j + 1);
                dp[i][j] %= mod;
            }
        return dp[l][n];
    }
};
// @lc code=end

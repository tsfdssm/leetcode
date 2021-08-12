/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 */

// @lc code=start
class Solution
{
public:
    int twoEggDrop(int n)
    {
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> dp(2, vector<int>(n + 1, inf));
        for (int i = 0; i <= n; ++i)
            dp[0][i] = i;
        dp[1][0] = 0;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                dp[1][i] = min(dp[1][i], max(dp[0][j - 1], dp[1][i - j]) + 1);
        }

        return dp[1][n];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        int cnt = 1;
        while (cnt * cnt < n)
            ++cnt;
        if (n == cnt * cnt)
            return 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < cnt; ++j)
                if (j * j <= i)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};
// @lc code=end

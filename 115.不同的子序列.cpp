/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
                else
                    dp[i + 1][j + 1] = dp[i][j + 1];
            }
        return (int)dp[m][n];
    }
};
// @lc code=end

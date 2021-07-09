/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

// @lc code=start
class Solution
{
public:
    int countPalindromicSubsequences(const string &s)
    {
        int n = s.size();
        const int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                for (int k = 0; k < 4; ++k)
                {
                    char c = 'a' + k;
                    if (i == j)
                    {
                        if (s[i] == c)
                            dp[k][i][j] = 1;
                        continue;
                    }
                    if (c != s[i])
                        dp[k][i][j] = dp[k][i + 1][j];
                    else if (c != s[j])
                        dp[k][i][j] = dp[k][i][j - 1];
                    else
                    {
                        dp[k][i][j] = 2;
                        for (int m = 0; m < 4; ++m)
                        {
                            dp[k][i][j] += dp[m][i + 1][j - 1];
                            dp[k][i][j] %= mod;
                        }
                    }
                }
        int res = 0;
        for (int i = 0; i < 4; ++i)
        {
            res += dp[i][0][n - 1];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end

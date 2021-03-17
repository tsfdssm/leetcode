/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        if (0 == s.size())
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, true));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++i)
        {
            if (dp[0][i])
                f[i] = 0;
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    if (true == dp[j + 1][i])
                        f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n - 1];
    }
};
// @lc code=end

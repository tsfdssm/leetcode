/*
 * @lc app=leetcode.cn id=903 lang=cpp
 *
 * [903] DI 序列的有效排列
 */

// @lc code=start
class Solution
{
public:
    int numPermsDISequence(string s)
    {
        int n = s.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        //dp[i][j],长度i,j结尾
        //for (int j = 0; j <= n; ++j)
        //dp[0][j] = 1;

        // for (int i = 1; i <= n; ++i)
        // {
        //     for (int j = 0; j <= n; ++j)
        //     {
        //         char c = s[i - 1];
        //         if (c == 'D')
        //         {
        //             for (int k = j; k < i; ++k)
        //             {
        //                 dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        //             }
        //         }
        //         else
        //         {
        //             for (int k = 0; k < j; ++k)
        //             {
        //                 dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        //             }
        //         }
        //     }
        // }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            char c = s[i - 1];
            if (c == 'D')
            {
                dp[i][i] = 0;
                for (int j = i - 1; j >= 0; --j)
                {
                    dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                }
            }
            else
            {
                dp[i][0] = 0;
                for (int j = 1; j <= i; ++j)
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
                }
            }
        }

        // for (int i = 1; i <= n; ++i)
        // {
        //     char c = s[i - 1];
        //     if (c == 'D')
        //     {
        //         dp[i][n] = 0;
        //         for (int j = 0; j < n; ++j)
        //         {

        //             for (int k = j + 1; k <= n; ++k)
        //             {
        //                 dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         dp[i][0] = 0;
        //         for (int j = 1; j <= n; ++j)
        //         {
        //             for (int k = j - 1; k >= 0; --k)
        //             {
        //                 dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
        //             }
        //         }
        //     }
        // }
        int res = 0;
        for (int i = 0; i <= n; ++i)
        {
            res += dp[n][i];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(const string &s)
    {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            int l = i / 2;
            int r = i / 2 + (i & 1);
            while (l >= 0 && r < n && s[l] == s[r])
            {
                res++;
                --l;
                ++r;
            }
        }
        return res;
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for (int i = 0; i < n; ++i)
        //     dp[i][i] = 1;
        // for (int j = 1; j < n; ++j)
        //     for (int i = j - 1; i >= 0; --i)
        //     {
        //         dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        //         if (s[i] == s[j])
        //             dp[i][j]++;
        //     }
        // return dp[0][n - 1];
    }
};
// @lc code=end

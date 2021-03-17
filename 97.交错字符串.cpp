/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int n = s1.size(), m = s2.size(), t = s3.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
            {
                int p = i + j - 1;
                if (i > 0)
                    dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[p];
                if (j > 0)
                    dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[p];
            }
        return dp[n][m];
    }
};
// @lc code=end

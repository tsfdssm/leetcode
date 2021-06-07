/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i)
            dp[m][i] = m;
        for (int i = m - 1; i >= 0; --i)
            for (int j = 0; j < 26; ++j)
            {
                if (t[i] == j + 'a')
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        int add = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[add][s[i] - 'a'] == m)
                return false;
            add = dp[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
public:
    vector<int> get(const string &s)
    {
        vector<int> res(2, 0);
        for (const char c : s)
            res[c - '0']++;
        return res;
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= len; ++i)
        {
            auto &&vec = get(strs[i - 1]);
            int zeros = vec[0];
            int ones = vec[1];
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= n; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                }
        }
        return dp[len][m][n];
    }
};
// @lc code=end

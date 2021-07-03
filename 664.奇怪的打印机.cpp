/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 */

// @lc code=start
class Solution
{
public:
    int strangePrinter(string &s)
    {
        string cur;
        for (char c : s)
        {
            if (cur.size() > 0 && cur.back() == c)
                continue;
            cur += c;
        }
        int n = cur.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int j = 1; j < n; ++j)
            for (int i = j - 1; i >= 0; --i)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
                if (cur[i] != cur[j])
                {
                    int minn = INT_MAX;
                    for (int k = i; k < j; ++k)
                    {
                        minn = min(minn, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = minn;
                }
            }
        return dp[0][n - 1];
    }
};
// @lc code=end

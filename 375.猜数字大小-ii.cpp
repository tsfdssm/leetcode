/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution
{
public:
    int getMoneyAmount(int n)
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; ++len)
        {
            for (int st = 1; st <= n - len + 1; ++st)
            {
                int tmp = INT_MAX;
                for (int mid = st + (len - 1) / 2; mid < st + len - 1; ++mid)
                {

                    int res = mid + max(dp[st][mid - 1], dp[mid + 1][st + len - 1]);
                    tmp = min(tmp, res);
                }
                dp[st][st + len - 1] = tmp;
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

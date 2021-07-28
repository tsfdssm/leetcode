/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> dp(100, 0.0);
        dp[0] = (double)poured;
        while (query_row > 0)
        {
            vector<double> nxt(100, 0.0);
            for (int idx = 0; idx < 100; ++idx)
            {
                if (dp[idx] <= 1.0)
                    continue;
                double over = (dp[idx] - 1.0) / 2;
                nxt[idx] += over;
                nxt[idx + 1] += over;
            }
            dp = std::move(nxt);
            --query_row;
        }
        return min(dp[query_glass], 1.0);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i)
        {
            if (stones[i] - stones[i - 1] > i)
                return false;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                int k = stones[i] - stones[j];
                if (k > j + 1)
                {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                // if (i == n - 1 && dp[i][k])
                //     return true;
            }
        }
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end

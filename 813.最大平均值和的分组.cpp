/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<double> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + nums[i];
        vector<vector<double>> dp(n, vector<double>(k, 0)); //dp[i][j]：[0...i],数组划分为j+1份
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = sum[i] / (i + 1);
            for (int j = 1; j < k && j <= i; ++j)
            {
                for (int t = j - 1; t < i; ++t)
                {
                    dp[i][j] = max(dp[i][j], dp[t][j - 1] + (sum[i] - sum[t]) / (i - t));
                }
            }
        }
        return dp[n - 1][k - 1];
    }
};
// @lc code=end

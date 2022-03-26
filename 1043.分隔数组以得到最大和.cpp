/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            int curMax = 0;
            for (int j = i - 1; j >= 0 && i - j <= k; --j)
            {
                curMax = max(curMax, arr[j]);
                dp[i] = max(dp[i], dp[j] + (i - j) * curMax);
            }
        }
        return dp[n];
    }
};
// @lc code=end

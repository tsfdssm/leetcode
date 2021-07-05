/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] <= dp[j])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                        cnt[i] += cnt[j];
                }
            }
        }
        int maxn = *max_element(dp.begin(), dp.end());
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (dp[i] == maxn)
                res += cnt[i];
        return res;
    }
};
// @lc code=end

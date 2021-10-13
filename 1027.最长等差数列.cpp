/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        int maxn = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(maxn * 2 + 1));
        int res = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
            {
                int dis = nums[j] - nums[i] + maxn;
                dp[i][dis] = max(dp[i][dis], dp[j][dis] + 1);
                res = max(res, dp[i][dis]);
            }
        return res + 1;
    }
};
// @lc code=end

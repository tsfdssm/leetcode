/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        // vector<int> psum(n + 1);
        // for (int i = 0; i < n; ++i)
        //     psum[i + 1] = (psum[i] + nums[i]) % k;
        int psum = 0;
        const int diff = k * 10000;
        vector<int> dp(k, 0);
        for (int i = 0; i < n; ++i)
        {
            psum = (psum + nums[i] + diff) % k;
            dp[psum]++;
        }
        int res = dp[0] * (dp[0] + 1) / 2;
        for (int i = 1; i < k; ++i)
        {
            if (dp[i] < 2)
                continue;
            res += dp[i] * (dp[i] - 1) / 2;
        }
        return res;
    }
};
// @lc code=end

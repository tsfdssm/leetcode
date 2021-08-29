/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int len = (1 << 16);
        vector<int> dp(len, 0);
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[nums[i] & nums[j]]++;
        int res = 0;
        for (int i : nums)
        {
            for (int j = 0; j < len; ++j)
                if (0 == (i & j))
                    res += dp[j];
        }
        return res;
    }
};
// @lc code=end

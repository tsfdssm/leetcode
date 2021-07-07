/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        if (1 == k)
            return true;
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > target)
            return false;
        int size = 1 << len;
        vector<bool> dp(size, false);
        dp[0] = true;
        vector<int> cur(size);
        for (int i = 0; i < size; ++i)
        {
            if (!dp[i])
                continue;
            for (int j = 0; j < len; j++)
            {
                if (i & (1 << j) != 0)
                    continue;
                int nxt = i | (1 << j);
                if (dp[nxt])
                    continue;
                if (cur[i] % target + nums[j] <= target)
                {
                    cur[nxt] = cur[i] + nums[j];
                    dp[nxt] = true;
                }
                else
                {
                    break;
                }
            }
        }
        return dp[size - 1];
    }
};
// @lc code=end

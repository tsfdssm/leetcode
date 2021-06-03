/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    // int res = 0;
    // int tar = 0;
    // void dfs(vector<int> &nums, int val)
    // {
    //     if (val == tar)
    //     {
    //         ++res;
    //         return;
    //     }
    //     if (val > tar)
    //         return;
    //     for (int &num : nums)
    //     {
    //         dfs(nums, val + num);
    //     }
    //     return;
    // }
    int combinationSum4(vector<int> &nums, int target)
    {

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            for (const int num : nums)
            {
                if (i >= num && dp[i] < INT_MAX - dp[i - num])
                    dp[i] += dp[i - num];
            }
        }

        return dp.back();
    }
};
// @lc code=end

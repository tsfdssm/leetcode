/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
public:
    // int sum = 0;
    // bool dfs(vector<int> &nums, int i, int target)
    // {
    //     if (i >= nums.size())
    //         return false;
    //     if (sum > target)
    //         return false;
    //     if (sum == target)
    //         return true;
    //     if (nums[i] == target)
    //         return true;
    //     sum += nums[i];
    //     if (dfs(nums, i + 1, target))
    //         return true;
    //     sum -= nums[i];

    //     return dfs(nums, i + 1, target);
    // }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() < 2)
            return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (1 == (target & 1))
            return false;
        target >>= 1;
        if (*max_element(nums.begin(), nums.end()) > target)
            return false;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i)
        {
            int num = nums[i];
            for (int j = 1; j <= target; ++j)
            {
                if (num <= j)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
        // if (nums.size() < 2)
        //     return false;
        // int all = accumulate(nums.begin(), nums.end(), 0);
        // if (1 == (all & 1))
        //     return false;
        // all >>= 1;
        // if (*max_element(nums.begin(), nums.end()) > all)
        //     return false;
        // return dfs(nums, 0, all);
    }
};
// @lc code=end

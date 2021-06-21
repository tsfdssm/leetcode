/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    int res = 0;
    int t = 0;
    void dfs(vector<int> &nums, int i, int tmp)
    {
        if (i == nums.size())
        {
            if (tmp == t)
                ++res;
            return;
        }
        dfs(nums, i + 1, tmp + nums[i]);
        dfs(nums, i + 1, tmp - nums[i]);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        t = target;
        dfs(nums, 0, 0);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (0 == len)
            return 0;
        if (1 == len)
            return nums[0];
        if (2 == len)
            return max(nums[0], nums[1]);
        return max(robrange(nums, 0, len - 1), robrange(nums, 1, len));
    }
    int robrange(vector<int> &nums, int start, int end)
    {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; ++i)
        {
            int tmp = second;
            second = max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }
};
// @lc code=end

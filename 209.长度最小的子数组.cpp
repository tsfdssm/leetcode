/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (0 == n)
            return 0;
        int res = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= target)
            {
                res = min(res, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

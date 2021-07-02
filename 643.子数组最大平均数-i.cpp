/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double res = sum;
        int n = nums.size();
        for (int i = k; i < n; ++i)
        {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};
// @lc code=end

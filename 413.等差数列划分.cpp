/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        //vector<int> dp(n, 0);
        int sum = 0;
        int dp = 0;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                ++dp;
                sum += dp;
            }
            else
            {
                dp = 0;
            }
        }
        return sum;
        //return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        long long n = nums.size();

        long long sum = 0;
        for (int num : nums)
            sum += num;

        long long dp = 0;
        for (int i = 0; i < n; ++i)
        {
            dp += nums[i] * i;
        }
        long long res = dp;
        for (int i = n - 1; i > 0; --i)
        {

            dp += sum - (n)*nums[i];
            res = max(res, dp);
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();

        int sum = nums[0];
        int res = sum;
        for (int i = 1; i < n; ++i)
        {
            sum = nums[i] + (sum > 0 ? sum : 0);
            res = max(res, sum);
        }
        int minn = 0;
        sum = nums[0];
        for (int i = 1; i < n - 1; ++i)
        {
            sum = nums[i] + (sum < 0 ? sum : 0);
            minn = min(minn, sum);
        }
        res = max(res, accumulate(nums.begin(), nums.end(), 0) - minn);
        return res;
        // int n = nums.size();
        // int res = 0;
        // int sum = 0;
        // int l = 0, r = 0;
        // int cnt = 0;
        // while (cnt < 2 * n)
        // {
        //     sum += nums[r];
        //     ++cnt;
        //     if (0 >= sum)
        //     {
        //         sum = 0;
        //         l = r = (cnt % n);
        //     }
        //     else
        //     {
        //         res = max(sum, res);
        //         ++r;
        //         r %= n;
        //         if (r == l)
        //         {
        //         }
        //     }
        // }
        // return res;
    }
};
// @lc code=end

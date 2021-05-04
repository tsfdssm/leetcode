/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int minF = nums[0];
        int maxF = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i)
        {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(mn * nums[i], nums[i]));
            minF = min(mx * nums[i], min(mn * nums[i], nums[i]));
            ans = max(ans, maxF);
            // maxF = max(maxF * nums[i], max(minF * nums[i], nums[i]));
            // minF = min(maxF * nums[i], min(minF * nums[i], nums[i]));
            // ans = max(ans, maxF);
        }
        return ans;
    }
};
// @lc code=end

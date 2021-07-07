/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int multi = 1;
        int res = 0;
        while (l < n)
        {
            while (r < n && multi < k)
            {
                multi *= nums[r];
                ++r;
            }
            if (l == r)
            {
                ++l;
                ++r;
                continue;
            }
            if (multi >= k)
            {
                --r;
                multi /= nums[r];
            }
            res += r - l;
            multi /= nums[l];
            ++l;
        }
        return res;
    }
};
// @lc code=end

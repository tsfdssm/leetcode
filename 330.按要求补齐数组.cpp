/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long x = 1;
        int res = 0;
        int idx = 0;
        int k = nums.size();
        while (x <= n)
        {
            if (idx < k && nums[idx] <= x)
            {
                x += nums[idx];
                ++idx;
            }
            else
            {
                x *= 2;
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

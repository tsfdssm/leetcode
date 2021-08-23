/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        if (1 >= n)
            return 0;
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > last)
            {
                last = nums[i];
            }
            else
            {
                ++last;
                res += last - nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

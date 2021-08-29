/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
                return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;
    }
};
// @lc code=end

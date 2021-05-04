/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
            {
                if (mid > 0 && nums[mid - 1] < nums[mid])
                {
                    return mid;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};
// @lc code=end

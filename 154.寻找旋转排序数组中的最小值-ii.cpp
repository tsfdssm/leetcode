/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (0 == nums.size())
            return 0;
        if (nums.front() < nums.back())
            return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) //left bigger
            {
                l = mid + 1;
            }
            else if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else //nl==nr;
            {
                --r;
            }
        }
        return nums[l];
    }
};
// @lc code=end

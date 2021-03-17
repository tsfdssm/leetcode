/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (0 == n)
            return false;
        if (1 == n)
            return target == nums[0] ? true : false;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return true;
            if (nums[l] == nums[mid])
            {
                l++;
                continue;
            }
            else if (nums[l] < nums[mid])
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2, -1);
        int n = nums.size();
        if (0 == n)
            return res;
        if (1 == n && target != nums[0])
            return res;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    res[0] = mid;
                    break;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (res[0] == -1)
            return res;
        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                if (mid == n - 1 || nums[mid + 1] != target)
                {
                    res[1] = mid;
                    break;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};
// @lc code=end

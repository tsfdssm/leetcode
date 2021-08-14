/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int i = 0, j = 1;
        int n = nums.size();
        while (i < n && j < n)
        {
            while (i < n && nums[i] % 2 == 0)
                i += 2;
            while (j < n && nums[j] % 2 == 1)
                j += 2;
            if (i >= n || j >= n)
                break;
            swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
        return nums;
    }
};
// @lc code=end

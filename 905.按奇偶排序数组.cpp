/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            while (l < r && !(nums[l] & 1))
                ++l;
            while (l < r && (nums[r] & 1))
                --r;
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};
// @lc code=end

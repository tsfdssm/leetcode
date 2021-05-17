/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n)
        {
            if (nums[j])
            {
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        }
    }
};
// @lc code=end

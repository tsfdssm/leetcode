/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int n = nums.size();
        int i = n - 2, j = 0;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            for (j = n - 1; j >= 0 && nums[j] <= nums[i]; j--)
                ;

            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

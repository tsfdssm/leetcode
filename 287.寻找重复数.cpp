/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == (nums[i] - 1))
                continue;
            if (nums[i] == nums[nums[i] - 1])
                return nums[i];
            swap(nums[i], nums[nums[i] - 1]);
            --i;
        }
        return -1;
    }
};
// @lc code=end

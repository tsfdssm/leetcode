/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int n = nums.size();

        int idx = 0;
        while (idx < n - 1 && nums[idx + 1] == nums[idx])
            ++idx;

        if (idx == n - 1)
            return true;
        int flag = 1;
        if (nums[idx + 1] - nums[idx] < 0)
            flag = -1;
        ++idx;
        while (idx < n - 1)
        {
            if ((nums[idx + 1] - nums[idx]) * flag < 0)
                return false;
            ++idx;
        }
        return true;
    }
};
// @lc code=end

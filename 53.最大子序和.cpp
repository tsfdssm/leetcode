/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxRes = nums[0];
        for (const int &i : nums)
        {
            pre = pre <= 0 ? i : pre + i;
            maxRes = maxRes > pre ? maxRes : pre;
        }
        return maxRes;
    }
};
// @lc code=end

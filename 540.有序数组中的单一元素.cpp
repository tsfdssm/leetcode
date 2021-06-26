/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int res = 0;
        for (const auto num : nums)
            res ^= num;
        return res;
    }
};
// @lc code=end

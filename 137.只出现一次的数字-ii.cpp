/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int once = 0, twice = 0;
        for (const auto &i : nums)
        {
            once = ~twice & (once ^ i);
            twice = ~once & (twice ^ i);
        }
        return once;
    }
};
// @lc code=end

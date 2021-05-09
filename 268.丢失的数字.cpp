/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int num : nums)
            sum += num;
        return ((1 + n) * n) / 2 - sum;
    }
};
// @lc code=end

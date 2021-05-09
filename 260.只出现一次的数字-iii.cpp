/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        if (nums.size() <= 3)
            return nums;
        int n = nums.size();
        long long ab = 0;
        int a = 0, b = 0;
        for (int num : nums)
            ab ^= num;
        long long div = ab & (-ab);
        for (int num : nums)
        {
            if (0 == (num & div))
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        return {a, b};
    }
};
// @lc code=end

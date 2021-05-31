/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int small = INT_MAX, mid = INT_MAX;
        for (int num : nums)
        {
            if (num <= small)
            {
                small = num;
            }
            else if (num <= mid)
            {
                mid = num;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i += 2)
            res += nums[i];
        return res;
    }
};
// @lc code=end

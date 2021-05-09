/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int l = 1;
        int r = 1;
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n - 1; ++i)
        {
            l *= nums[i];
            res[i + 1] = l;
        }
        for (int i = n - 1; i > 0; --i)
        {
            r *= nums[i];
            res[i - 1] *= r;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        string res;
        int n = nums.size();
        if (1 == n)
            return to_string(nums[0]);
        for (int i = 0; i < n; ++i)
        {
            res += to_string(nums[i]);

            if (i != n - 1)
                res += '/';
            else if (n > 2)
                res += ')';
            if (0 == i && n > 2)
                res += '(';
        }
        return res;
    }
};
// @lc code=end

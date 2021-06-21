/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int tmp = 0;
        for (const int num : nums)
        {
            if (1 == num)
            {
                ++tmp;
                res = res >= tmp ? res : tmp;
            }
            else
                tmp = 0;
        }
        return res;
    }
};
// @lc code=end

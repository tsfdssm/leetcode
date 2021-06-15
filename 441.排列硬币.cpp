/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long sum = 0;
        long long i = 0;
        while (sum < n)
        {
            ++i;
            sum += i;
        }
        if (sum != n)
            --i;
        return (int)i;
    }
};
// @lc code=end

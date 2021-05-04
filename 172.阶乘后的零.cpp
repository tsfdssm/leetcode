/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n > 0)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};
// @lc code=end

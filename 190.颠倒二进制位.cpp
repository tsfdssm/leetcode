/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0, power = 31;
        while (n > 0)
        {
            res += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        return res;
    }
};
// @lc code=end

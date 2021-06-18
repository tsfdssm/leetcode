/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        int res = 0;
        int mask = 1 << 30;
        while ((num & mask) == 0)
            mask >>= 1;

        while (mask != 0)
        {
            mask >>= 1;
            if (!(num & mask))
                res += mask;
        }
        return res;
    }
};
// @lc code=end

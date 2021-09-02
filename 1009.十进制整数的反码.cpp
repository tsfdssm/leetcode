/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int k = 31;
        while (k >= 0 && (n & (1 << k)) == 0)
            --k;
        if (-1 == k)
            return 1;
        while (k >= 0)
        {
            n ^= (1 << k);
            --k;
        }
        return n;
    }
};
// @lc code=end

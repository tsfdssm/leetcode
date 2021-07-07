/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool st = (n & 1);
        while (n > 0)
        {
            n >>= 1;
            if (!st ^ (n & 1))
                return false;
            else
                st = !st;
        }
        return true;
    }
};
// @lc code=end

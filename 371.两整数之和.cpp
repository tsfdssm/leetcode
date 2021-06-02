/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        int n = 0;
        int res = 0;
        int over = 0;
        while (n < 32)
        {
            int tmpa = 1 & a;
            int tmpb = 1 & b;
            res |= ((over ^ tmpa ^ tmpb) << n);
            over = (over & tmpa) | (over & tmpb) | (tmpa & tmpb);
            a >>= 1;
            b >>= 1;
            ++n;
        }
        return res;
    }
};
// @lc code=end

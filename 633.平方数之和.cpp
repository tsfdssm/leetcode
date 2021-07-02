/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution
{
public:
    inline bool isP(int x)
    {
        int sqrx = sqrt(x);
        return sqrx * sqrx == x;
    }
    bool judgeSquareSum(int c)
    {
        for (int i = 0; i * i <= c / 2; ++i)
            if (isP(c - i * i))
            {
                return true;
            }
        return false;
    }
};
// @lc code=end

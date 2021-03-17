/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long tmp = 0;
        long long res = tmp * tmp;
        while (res <= (long long)x)
        {
            tmp++;
            res = tmp * tmp;
        }
        return tmp - 1;
    }
};
// @lc code=end

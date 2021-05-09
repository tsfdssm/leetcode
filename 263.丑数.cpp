/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n < 0)
            n = -n;
        while (n % 5 == 0)
            n /= 5;
        while (n % 3 == 0)
            n /= 3;
        while (0 == n % 2)
            n /= 2;
        if (1 == n)
            return true;
        return false;
    }
};
// @lc code=end

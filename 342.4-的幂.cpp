/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (0 >= n)
            return false;
        while (0 == n % 4)
            n /= 4;
        if (1 == n)
            return true;
        return false;
    }
};
// @lc code=end

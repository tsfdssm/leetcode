/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (0 >= n)
            return false;
        while (0 == n % 3)
            n /= 3;
        if (1 != n)
            return false;
        return true;
    }
};
// @lc code=end

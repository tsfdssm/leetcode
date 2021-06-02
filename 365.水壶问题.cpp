/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (z > x + y || z < 0)
            return false;
        if (0 == x || 0 == y)
            return 0 == z || x + y == z;
        return 0 == z % gcd(x, y);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int res = 0;
        int power = 31;
        while (power >= 0)
        {
            if (((right - left) < (1 << power)) && right & 1 << power && left & 1 << power)
                res += 1 << power;
            power--;
        }
        return res;
    }
};
// @lc code=end

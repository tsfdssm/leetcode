/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        int power = 31;
        while (power >= 0)
        {
            if (n & 1 << power)
                cnt++;
            power--;
        }
        return cnt;
    }
};
// @lc code=end

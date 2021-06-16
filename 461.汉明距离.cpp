/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;
        int k = 0;
        while (k < 32)
        {
            int mask = 1 << k;
            if ((x & mask) != (y & mask))
                ++res;
            ++k;
        }
        return res;
    }
};
// @lc code=end

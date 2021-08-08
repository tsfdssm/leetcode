/*
 * @lc app=leetcode.cn id=858 lang=cpp
 *
 * [858] 镜面反射
 */

// @lc code=start
class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        while (!(p & 1) && !(q & 1))
        {
            p >>= 1;
            q >>= 1;
        }
        if (!(p & 1))
            return 2;
        if (!(q & 1))
            return 0;
        return 1;
    }
};
// @lc code=end

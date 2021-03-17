/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int x = 1, y = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = y;
            y = x + y;
            x = tmp;
        }
        return y;
    }
};
// @lc code=end

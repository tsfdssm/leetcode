/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution
{
public:
    int reachNumber(int target)
    {

        if (target < 0)
            target = -target;
        int i = 1;
        while (true)
        {
            int val = i * (i + 1) / 2;
            if (val == target || (val > target && !((val - target) & 1)))
                return i;
            ++i;
        }
        return -1;
    }
};
// @lc code=end

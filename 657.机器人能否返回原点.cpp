/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;
        for (char c : moves)
        {
            if ('R' == c)
                ++x;
            else if ('L' == c)
                --x;
            else if ('U' == c)
                ++y;
            else
                --y;
        }
        return x == 0 && y == 0;
    }
};
// @lc code=end

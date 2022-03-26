/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution
{
public:
    bool isRobotBounded(string ins)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int d = 0;
        // 'L' d--;
        // 'R' d++;
        int n = ins.size();
        int x = 0;
        int y = 0;
        for (char c : ins)
        {
            if ('G' == c)
            {
                x += dx[d];
                y += dy[d];
            }
            else if ('L' == c)
            {
                --d;
                d += 4;
                d %= 4;
            }
            else
            {
                ++d;
                d %= 4;
            }
        }
        if (0 == x && 0 == y)
            return true;
        if (0 != d)
            return true;
        return false;
    }
};
// @lc code=end

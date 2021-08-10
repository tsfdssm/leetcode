/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int res = 0;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        int direction = 0;
        int x = 0, y = 0;
        set<pair<int, int>> st;
        for (auto &e : obstacles)
            st.insert({e[0], e[1]});
        for (int num : commands)
        {
            if (-2 == num)
            {
                direction++;
                direction %= 4;
            }
            else if (-1 == num)
            {
                direction--;
                direction = (direction + 4) % 4;
            }
            else
            {
                while (num > 0 && !st.count({x + dx[direction], y + dy[direction]}))
                {
                    x += dx[direction];
                    y += dy[direction];
                    --num;
                }
                res = max(res, x * x + y * y);
            }
        }
        return res;
    }
};
// @lc code=end

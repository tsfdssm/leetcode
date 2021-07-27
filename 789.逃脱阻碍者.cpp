/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

// @lc code=start
class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int len = abs(target[0]) + abs(target[1]);
        for (auto &point : ghosts)
        {
            if (len >= (abs(point[0] - target[0]) + abs(point[1] - target[1])))
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        int x0 = points[0][0];
        int y0 = points[0][1];
        int x1 = points[1][0];
        int y1 = points[1][1];
        int x2 = points[2][0];
        int y2 = points[2][1];

        return !((y1 - y0) * (x2 - x0) == (y2 - y0) * (x1 - x0));
    }
};
// @lc code=end

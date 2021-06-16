/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        if (0 == n)
            return 0;
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });

        int res = 1;
        int st = points[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (st < points[i][0])
            {
                ++res;
                st = points[i][1];
            }
        }
        return res;
    }
};
// @lc code=end

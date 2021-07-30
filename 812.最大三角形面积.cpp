/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double res;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    res = max(res, area(points[i], points[j], points[k]));
        return res;
    }

    inline double area(vector<int> &p, vector<int> &q, vector<int> &r)
    {
        int a = q[0] - p[0], b = q[1] - p[1];
        int c = r[0] - p[0], d = r[1] - p[1];
        return 0.5 * abs(a * d - b * c);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
 */

// @lc code=start
class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int n = points.size();
        int res = INT_MAX;
        set<pair<int, int>> st;
        for (int i = 0; i < n; ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            st.insert({x1, y1});
        }
        for (int i = 0; i < n; ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; ++j)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2)
                    continue;
                if (st.count({x1, y2}) && st.count({x2, y1}))
                {
                    res = min(res, abs((x2 - x1) * (y2 - y1)));
                }
            }
        }
        //return res;
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end

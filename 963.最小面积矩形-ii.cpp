/*
 * @lc app=leetcode.cn id=963 lang=cpp
 *
 * [963] 最小面积矩形 II
 */

// @lc code=start
class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        unordered_set<long> st;
        int n = points.size();
        for (int i = 0; i < n; ++i)
            st.insert((long)points[i][0] * 50000 + points[i][1]);

        double maxRes = 40000.0 * 40000.0;
        double res = maxRes;
        for (int i = 0; i < n; ++i)
        {
            vector<int> &p1 = points[i];
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                vector<int> &p2 = points[j];
                for (int k = j + 1; k < n; ++k)
                {
                    if (i == k)
                        continue;
                    vector<int> &p3 = points[k];

                    int p4x = p2[0] + p3[0] - p1[0];
                    int p4y = p2[1] + p3[1] - p1[1];
                    if (st.count((long)p4x * 50000 + p4y))
                    {
                        if ((p2[0] - p1[0]) * (p3[0] - p1[0]) + (p2[1] - p1[1]) * (p3[1] - p1[1]) == 0)
                        {
                            res = min(res, Area(p1, p2, p3));
                        }
                    }
                }
            }
        }
        return abs(maxRes - res) <= 0.000001 ? 0.0 : res;
    }
    double Area(vector<int> &p1, vector<int> &p2, vector<int> &p3)
    {
        return sqrt((double)pow(p1[0] - p2[0], 2) + (double)pow(p1[1] - p2[1], 2)) *
               sqrt((double)pow(p1[0] - p3[0], 2) + (double)pow(p1[1] - p3[1], 2));
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const pair<T1, T2> &p) const
    {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        unordered_map<pair<double, double>, set<int>, pair_hash> res;
        unordered_map<double, set<int>> special;
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                int x0 = points[i][0], y0 = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];
                if (x0 == x1)
                {
                    special[x0].insert(i);
                    special[x0].insert(j);
                    continue;
                }
                double k0 = 1.0 * (y1 - y0) / (x1 - x0);
                double b0 = ((double)y0 - k0 * (x0));

                res[pair<double, double>(k0, b0)].insert(i);
                res[pair<double, double>(k0, b0)].insert(j);
            }
        }
        unsigned long ans = 1;
        for (auto it = special.begin(); it != special.end(); it++)
            ans = max(ans, it->second.size());

        for (auto it = res.begin(); it != res.end(); it++)
            ans = max(ans, it->second.size());
        return ans;
    }
};
// @lc code=end

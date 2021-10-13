/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [&](const auto &a, const auto &b)
             { return (a[0] - a[1]) < b[0] - b[1]; });
        int res = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; ++i)
            res += costs[i][0];
        for (int i = n; i < 2 * n; ++i)
            res += costs[i][1];
        return res;
    }
};
// @lc code=end

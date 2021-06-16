/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;
        unordered_map<int, int> mp;
        int n = points.size();
        for (int i = 0; i < n; ++i)
        {
            mp.clear();
            for (int j = 0; j < n; ++j)
            {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                ++mp[dx * dx + dy * dy];
            }
            for (const auto &it : mp)
                res += it.second * (it.second - 1);
        }
        return res;
    }
};
// @lc code=end

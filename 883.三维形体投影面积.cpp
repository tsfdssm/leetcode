/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        vector<int> xz(51, 0);
        vector<int> yz(51, 0);

        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                {
                    ++res;
                    xz[i] = max(xz[i], grid[i][j]);
                    yz[j] = max(yz[j], grid[i][j]);
                }
            }
        res += accumulate(xz.begin(), xz.end(), 0);
        res += accumulate(yz.begin(), yz.end(), 0);
        return res;
    }
};
// @lc code=end

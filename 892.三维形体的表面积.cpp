/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (0 == grid[i][j])
                    continue;
                res += 4 * grid[i][j] + 2;
                for (int k = 0; k < 4; ++k)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || m <= ni || nj < 0 || n <= nj || (0 == grid[ni][nj]))
                        continue;
                    res -= min(grid[i][j], grid[ni][nj]);
                }
            }

        return res;
    }
};
// @lc code=end

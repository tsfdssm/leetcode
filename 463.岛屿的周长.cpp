/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (1 == grid[i][j])
                {
                    if (0 == i || 0 == grid[i - 1][j])
                        ++res;
                    if (0 == j || 0 == grid[i][j - 1])
                        ++res;
                }
        return res << 1;
    }
};
// @lc code=end

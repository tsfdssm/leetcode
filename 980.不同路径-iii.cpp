/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int cnt0 = 0;
        int sx = 0, sy = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (0 == grid[i][j])
                    ++cnt0;
                else if (1 == grid[i][j])
                {
                    sx = i;
                    sy = j;
                }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int res = 0;
        function<void(int, int, int)> dfs = [&](int x, int y, int cnt) {
            if (cnt > cnt0)
                return;
            if (2 == grid[x][y])
            {
                if (cnt == cnt0)
                    ++res;
                return;
            }
            if (-1 == grid[x][y])
                return;
            if (0 == grid[x][y])
                ++cnt;
            grid[x][y] = -1;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                    continue;
                if (-1 == grid[nx][ny])
                    continue;
                dfs(nx, ny, cnt);
            }
            grid[x][y] = 0;
        };
        dfs(sx, sy, 0);
        return res;
    }
};
// @lc code=end

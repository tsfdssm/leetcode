/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        if (grid[row][col] == color)
            return grid;
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        auto inGrid = [&](int x, int y)
        {
            return 0 <= x && x < m && 0 <= y && y < n;
        };
        auto pos = [&](int x, int y)
        {
            return x * n + y;
        };
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<int> q;
        q.push(pos(row, col));
        vis[row][col] = 1;
        int org = grid[row][col];
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int x = cur / n;
            int y = cur % n;
            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!inGrid(nx, ny))
                {
                    grid[x][y] = color;
                    continue;
                }
                if (vis[nx][ny])
                    continue;
                if (org != grid[nx][ny])
                {
                    grid[x][y] = color;
                    continue;
                }
                vis[nx][ny] = 1;
                q.push(pos(nx, ny));
            }
        }
        return grid;
    }
};
// @lc code=end

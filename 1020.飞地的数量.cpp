/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        auto bfs = [&](int i, int j)
        {
            queue<int> q;
            q.push(i * n + j);
            while (!q.empty())
            {
                auto cur = q.front();
                int curi = cur / n;
                int curj = cur % n;
                grid[curi][curj] = 0;
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int ni = curi + dx[k];
                    int nj = curj + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    if (0 == grid[ni][nj])
                        continue;
                    q.push(ni * n + nj);
                }
            }
        };

        for (int i = 0; i < m; ++i)
        {
            if (grid[i][0] == 1)
                bfs(i, 0);
            if (grid[i][n - 1] == 1)
                bfs(i, n - 1);
        }
        for (int j = 0; j < n; ++j)
        {
            if (grid[0][j] == 1)
                bfs(0, j);
            if (grid[m - 1][j] == 1)
                bfs(m - 1, j);
        }
        int cnt = 0;
        for (int i = 1; i + 1 < m; ++i)
            for (int j = 1; j + 1 < n; ++j)
            {
                if (grid[i][j])
                    ++cnt;
            }
        return cnt;
    }
};
// @lc code=end

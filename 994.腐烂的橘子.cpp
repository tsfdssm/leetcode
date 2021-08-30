/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        auto inGrid = [&](int x, int y) -> bool {
            return 0 <= x && x < m && 0 <= y && y < n;
        };
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int cnt1 = 0;
        queue<int> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (2 == grid[i][j])
                {
                    q.push(i * n + j);
                    grid[i][j] = 0;
                }
                else if (1 == grid[i][j])
                {
                    cnt1++;
                }
            }
        if (cnt1 == 0)
            return 0;
        int res = 0;
        int cnt = 0;
        while (!q.empty())
        {
            int len = q.size();
            ++res;
            for (int i = 0; i < len; ++i)
            {
                int cur = q.front();
                q.pop();
                int x = cur / n;
                int y = cur % n;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (!inGrid(nx, ny))
                        continue;
                    if (1 == grid[nx][ny])
                    {
                        ++cnt;
                        if (cnt == cnt1)
                            return res;
                        grid[nx][ny] = 0;
                        q.push(nx * n + ny);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        auto in_grid = [&](int x, int y) -> bool {
            return 0 <= x && x < n && 0 <= y && y < n;
        };
        queue<int> q;
        queue<int> q0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (0 == grid[i][j])
                    continue;
                vis[i][j] = 1;
                q.push(i * n + j);
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    int i = cur / n;
                    int j = cur % n;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (!in_grid(ni, nj))
                            continue;
                        if (vis[ni][nj])
                            continue;
                        vis[ni][nj] = 1;
                        if (grid[ni][nj])
                            q.push(ni * n + nj);
                        else
                            q0.push(ni * n + nj);
                    }
                }
                int res = 1;
                while (!q0.empty())
                {
                    int len = q0.size();
                    for (int s = 0; s < len; ++s)
                    {
                        int cur = q0.front();
                        q0.pop();
                        int i = cur / n;
                        int j = cur % n;
                        for (int k = 0; k < 4; ++k)
                        {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (!in_grid(ni, nj))
                                continue;
                            if (vis[ni][nj])
                                continue;
                            vis[ni][nj] = 1;
                            if (grid[ni][nj])
                                return res;
                            else
                                q0.push(ni * n + nj);
                        }
                    }
                    ++res;
                }
            }
        return -1;
    }
};
// @lc code=end

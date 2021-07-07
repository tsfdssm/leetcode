/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        queue<int> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if ((grid[i][j] == 0) || vis[i][j])
                    continue;
                vis[i][j] = true;
                q.push(i * n + j);
                int tmp = 0;
                while (!q.empty())
                {
                    int cur = q.front();
                    int row = cur / n;
                    int col = cur % n;
                    for (int k = 0; k < 4; ++k)
                    {
                        int tmpr = row + dir_x[k];
                        int tmpc = col + dir_y[k];
                        if (tmpr < 0 || tmpr >= m || tmpc < 0 || tmpc >= n || (0 == grid[tmpr][tmpc]) || vis[tmpr][tmpc])
                            continue;
                        vis[tmpr][tmpc] = true;
                        q.push(tmpr * n + tmpc);
                    }
                    q.pop();
                    tmp++;
                }
                res = max(res, tmp);
            }
        return res;
    }
};
// @lc code=end

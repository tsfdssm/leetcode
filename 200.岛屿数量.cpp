/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (0 == grid.size())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        const auto &dfs = [&](int i, int j, int cnt, const auto &dfs) {
            if (i < 0 || i >= m || j < 0 || j >= n)
                return;
            if (0 != vis[i][j] || '0' == grid[i][j])
                return;
            vis[i][j] = cnt;
            dfs(i - 1, j, cnt, dfs);
            dfs(i + 1, j, cnt, dfs);
            dfs(i, j - 1, cnt, dfs);
            dfs(i, j + 1, cnt, dfs);
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (0 != vis[i][j] || '0' == grid[i][j])
                    continue;
                res++;
                dfs(i, j, res, dfs);
            }

        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        if (0 == m)
            return {};
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] != 0)
                    continue;
                q.push({i, j});
                vis[i][j] = 1;
            }
        int level = 1;
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        vector<vector<int>> res;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                const auto &cur = q.front();
                int x = cur.first;
                int y = cur.second;
                q.pop();
                for (int j = 0; j < 4; ++j)
                {
                    int tx = x + dir_x[j];
                    int ty = y + dir_y[j];
                    if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty])
                        continue;
                    vis[tx][ty] = 1;
                    q.push({tx, ty});
                    mat[tx][ty] = level;
                }
            }
            level++;
        }
        return mat;
    }
};
// @lc code=end

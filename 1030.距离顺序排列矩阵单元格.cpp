/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int m, int n, int r0, int c0)
    {
        queue<int> q;
        vector<vector<int>> res;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        q.push(r0 * n + c0);
        vector<int> vis(m * n);
        vis[r0 * n + c0] = 1;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto cur = q.front();
                q.pop();
                int x = cur / n;
                int y = cur % n;
                res.push_back({x, y});
                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx * n + ny])
                        continue;
                    q.push(nx * n + ny);
                    vis[nx * n + ny] = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

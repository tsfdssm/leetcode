/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        if (0 == m)
            return {};
        int n = heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        for (int i = 0; i < n; ++i)
        {
            vis[0][i] += 1;
            q.push({heights[0][i], i});
        }

        for (int i = 1; i < m; ++i)
        {
            vis[i][0] += 1;
            q.push({heights[i][0], i * n});
        }

        while (!q.empty())
        {
            const auto &cur = q.top();
            int h = cur.first;
            int i = cur.second / n;
            int j = cur.second % n;
            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                i += x[k];
                j += y[k];
                if (0 <= i && i < m && 0 <= j && j < n && !(vis[i][j] & 1) && heights[i][j] >= h)
                {
                    vis[i][j] += 1;
                    q.push({heights[i][j], i * n + j});
                }
                i -= x[k];
                j -= y[k];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            vis[m - 1][i] += 2;
            q.push({heights[m - 1][i], (m - 1) * n + i});
        }

        for (int i = 0; i < m - 1; ++i)
        {
            vis[i][n - 1] += 2;
            q.push({heights[i][n - 1], i * n + n - 1});
        }

        while (!q.empty())
        {
            const auto &cur = q.top();
            int h = cur.first;
            int i = cur.second / n;
            int j = cur.second % n;
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                i += x[k];
                j += y[k];
                if (0 <= i && i < m && 0 <= j && j < n && !(vis[i][j] & 2) && heights[i][j] >= h)
                {
                    vis[i][j] += 2;
                    q.push({heights[i][j], i * n + j});
                }
                i -= x[k];
                j -= y[k];
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (vis[i][j] == 3)
                    res.push_back({i, j});
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start

class Solution
{
public:
    struct node
    {
        int x;
        int y;
        int k;
        int d;
        node(int _x = 0, int _y = 0, int _k = 0, int _d = 0) : x(_x), y(_y), k(_k), d(_d) {}
    };
    int R, C;
    int shortestPathAllKeys(vector<string> &grid)
    {
        R = grid.size();
        C = grid[0].size();
        node s;
        int keys = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if ('@' == grid[i][j])
                    s = node(i, j);
                else if ('a' <= grid[i][j] && grid[i][j] <= 'f')
                    keys |= (1 << (grid[i][j] - 'a'));
        queue<node> q;
        q.push(s);
        vector<vector<vector<int>>> vis(R, vector<vector<int>>(C, vector<int>(64, 0)));
        vis[s.x][s.y][0] = 1;
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
        while (!q.empty())
        {
            node cur = q.front();
            q.pop();
            if (cur.k == keys)
                return cur.d;
            for (int i = 0; i < 4; ++i)
            {
                const int nx = cur.x + dx[i];
                const int ny = cur.y + dy[i];
                if (in_grid(nx, ny) && grid[nx][ny] != '#' && !vis[nx][ny][cur.k])
                {
                    if ('A' <= grid[nx][ny] && grid[nx][ny] <= 'F' && !(cur.k & (1 << (grid[nx][ny] - 'A'))))
                        continue;
                    node next = node(nx, ny, cur.k, cur.d + 1);
                    if ('a' <= grid[nx][ny] && grid[nx][ny] <= 'f')
                        next.k |= (1 << (grid[nx][ny] - 'a'));
                    vis[nx][ny][next.k] = 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }

    bool in_grid(int x, int y)
    {
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};
// @lc code=end

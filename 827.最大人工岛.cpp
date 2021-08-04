/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> f;
    vector<int> _size;
    UnionFind(int n)
    {
        f.resize(n);
        _size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            f[i] = i;
    }

    int find(int x)
    {
        if (f[x] == x)
            return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {

        if (find(x) == find(y))
            return;
        if (x > y)
            swap(x, y);
        _size[find(x)] += _size[find(y)];
        f[find(y)] = find(x);
    }

    int size(int x)
    {
        return _size[find(x)];
    }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        UnionFind uf(m * n);
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int cnt0 = 0;
        queue<int> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    cnt0++;
                    continue;
                }
                if (vis[i][j])
                    continue;
                vis[i][j] = 1;

                q.push(i * n + j);
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    int curi = cur / n;
                    int curj = cur % n;
                    for (int k = 0; k < 4; ++k)
                    {
                        int tmpi = curi + dir_x[k];
                        int tmpj = curj + dir_y[k];
                        if (tmpi < 0 || tmpi >= m || tmpj < 0 || tmpj >= n || (0 == grid[tmpi][tmpj]))
                            continue;
                        if (vis[tmpi][tmpj])
                            continue;
                        vis[tmpi][tmpj] = 1;
                        q.push(tmpi * n + tmpj);
                        uf.merge(i * n + j, tmpi * n + tmpj);
                    }
                }
            }
        if (0 == cnt0)
            return m * n;
        int res = 0;
        set<int> all;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    continue;
                all.clear();
                for (int k = 0; k < 4; ++k)
                {
                    int tmpi = i + dir_x[k];
                    int tmpj = j + dir_y[k];
                    if (tmpi < 0 || tmpi >= m || tmpj < 0 || tmpj >= n)
                        continue;
                    if (grid[tmpi][tmpj] == 0)
                        continue;
                    all.insert(uf.find(tmpi * n + tmpj));
                }
                int tmp = 1;
                for (auto f : all)
                    tmp += uf.size(f);
                res = max(res, tmp);
            }
        return res;
    }
};
// @lc code=end

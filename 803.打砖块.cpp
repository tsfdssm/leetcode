/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> father;
    vector<int> _size;

    UnionFind(int n)
    {
        father.resize(n);
        _size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }

    int find(int x)
    {
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y)
    {
        if (find(x) == find(y))
            return;
        if (x < y)
            swap(x, y);
        _size[find(x)] += _size[find(y)];
        father[find(y)] = find(x);
    }

    int size(int x)
    {
        return _size[find(x)];
    }
};
class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int m = grid.size();
        int n = grid[0].size();
        int k = hits.size();
        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            auto row = hits[i][0];
            auto col = hits[i][1];
            if (grid[row][col] == 1)
            {
                res[i] = -1;
                grid[row][col] = 0;
            }
            else
            {
                res[i] = 0;
            }
        }
        UnionFind uf(m * n + 1);
        int s = m * n;
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};
        for (int j = 0; j < n; ++j)
            if (grid[0][j] == 1)
                uf.merge(s, j);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    continue;
                else
                    for (int t = 0; t < 4; ++t)
                    {
                        int tmpi = i + dir_x[t];
                        int tmpj = j + dir_y[t];
                        if (tmpi < 0 || tmpi >= m || tmpj < 0 || tmpj >= n || grid[tmpi][tmpj] == 0)
                            continue;
                        uf.merge(i * n + j, tmpi * n + tmpj);
                    }
        for (int t = k - 1; t >= 0; --t)
        {
            if (res[t] == 0)
                continue;
            auto i = hits[t][0];
            auto j = hits[t][1];
            int tmp = uf.size(s);
            grid[i][j] = 1;
            if (0 == i)
                uf.merge(s, j);
            for (int idx = 0; idx < 4; idx++)
            {
                int tmpi = i + dir_x[idx];
                int tmpj = j + dir_y[idx];
                if (tmpi < 0 || tmpi >= m || tmpj < 0 || tmpj >= n || grid[tmpi][tmpj] == 0)
                    continue;
                uf.merge(i * n + j, tmpi * n + tmpj);
            }
            res[t] = uf.size(s) - tmp - 1;
            if (res[t] < 0)
                res[t] = 0;
        }
        return res;
    }
};
// @lc code=end

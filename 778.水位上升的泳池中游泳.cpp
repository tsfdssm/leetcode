/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> f;
    UnionFind(int n)
    {
        f.resize(n);
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
        f[find(y)] = find(x);
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int len = n * n;
        vector<int> index(len);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                index[grid[i][j]] = i * n + j;
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};

        UnionFind uf(len);
        for (int i = 1; i < len; ++i)
        {
            int row = index[i] / n;
            int col = index[i] % n;
            for (int k = 0; k < 4; ++k)
            {
                int tmpi = row + dir_x[k];
                int tmpj = col + dir_y[k];
                if (tmpi < 0 || tmpi >= n || tmpj < 0 || tmpj >= n)
                    continue;
                if (grid[tmpi][tmpj] < grid[row][col])
                    uf.merge(index[i], tmpi * n + tmpj);
            }
            if (uf.isSame(0, len - 1))
                return i;
        }
        return -1;
    }
};
// @lc code=end

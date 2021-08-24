/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
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
        if (x == f[x])
            return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y)
    {
        f[find(y)] = find(x);
    }

    int size()
    {
        int res = 0;
        for (int i = 0; i < f.size(); ++i)
            if (f[i] == i)
                ++res;
        return res;
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        const int k = 1e4 + 5;
        int n = stones.size();
        vector<int> row(k, -1);
        vector<int> col(k, -1);
        UnionFind uf(n);

        for (int i = 0; i < n; ++i)
        {
            int r = stones[i][0];
            int c = stones[i][1];
            if (row[r] == -1)
            {
                row[r] = i;
            }
            else
            {
                uf.merge(row[r], i);
            }
            if (col[c] == -1)
            {
                col[c] = i;
            }
            else
            {
                uf.merge(i, col[c]);
            }
        }
        return n - uf.size();
    }
};
// @lc code=end

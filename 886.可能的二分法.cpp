/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
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
        if (f[x] == f[y])
            return;
        f[find(y)] = find(x);
    }

    bool isSame(int x, int y)
    {
        return f[x] == f[y];
    }
};
class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        UnionFind uf(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto &e : dislikes)
        {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        for (int u = 1; u <= n; ++u)
            for (auto v : adj[u])
            {
                if (uf.isSame(u, v))
                    return false;
                uf.merge(v, adj[u][0]);
            }
        return true;
    }
};
// @lc code=end

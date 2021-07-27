/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> parent;

    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(int x, int y)
    {
        parent[find(y)] = find(x);
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        UnionFind uf(n);
        for (int u = 0; u < n; ++u)
        {
            for (auto v : graph[u])
                if (uf.isSame(u, v))
                    return false;
            if (0 == graph[u].size())
                continue;
            int v = graph[u][0];
            for (int j = 1; j < graph[u].size(); ++j)
                uf.merge(v, graph[u][j]);
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> tree;

    void init(int len)
    {
        tree.resize(len);
        for (int i = 0; i < len; ++i)
            tree[i] = i;
    }
    int find(int x)
    {
        if (x == tree[x])
            return x;
        return tree[x] = find(tree[x]);
    }
    void merge(int x, int y)
    {
        tree[find(x)] = find(y);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        init(n + 1);
        vector<int> parent(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        int conflict = -1;
        int cycle = -1;

        for (int i = 0; i < n; ++i)
        {
            auto e = edges[i];
            int u = e[0];
            int v = e[1];
            if (parent[v] != v)
                conflict = i;
            else
            {
                parent[v] = u;
                if (find(v) == find(u))
                    cycle = i;
                else
                    merge(u, v);
            }
        }
        if (conflict < 0)
        {
            return edges[cycle];
        }
        else if (cycle >= 0)
        {
            return {parent[edges[conflict][1]], edges[conflict][1]};
        }
        else
        {
            return edges[conflict];
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=924 lang=cpp
 *
 * [924] 尽量减少恶意软件的传播
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
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        f[find(y)] = find(x);
    }

    int size(int x)
    {
        int res = 0;
        for (int i = 0; i < f.size(); ++i)
            if (f[i] == x)
                ++res;
        return res;
    }
};

class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();
        UnionFind uf(n);
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
                if (graph[u][v])
                    uf.merge(u, v);
        }

        int maxn = -1;
        int res = -1;
        unordered_map<int, int> mp;
        for (int init : initial)
            mp[uf.find(init)]++;
        sort(initial.begin(), initial.end());
        for (int init : initial)
        {
            int f = uf.find(init);
            int tmp;
            if (mp[f] > 1)
                tmp = 0;
            else
                tmp = uf.size(f);

            if (maxn < tmp)
            {
                maxn = tmp;
                res = init;
            }
        }
        return res;
    }
};
// @lc code=end

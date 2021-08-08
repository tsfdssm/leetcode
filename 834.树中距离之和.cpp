/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<int> res(n, 0);
        vector<int> cnt(n, 1);
        function<void(int, int)> dfs1 = [&](int u, int f) {
            for (int v : adj[u])
                if (v != f)
                {
                    dfs1(v, u);
                    cnt[u] += cnt[v];
                    res[u] += res[v] + cnt[v];
                }
        };

        function<void(int, int)> dfs2 = [&](int u, int f) {
            if (0 != u)
                res[u] = res[f] + n - 2 * cnt[u];
            for (int v : adj[u])
                if (v != f)
                    dfs2(v, u);
        };
        dfs1(0, -1);
        dfs2(0, -1);
        return res;

        // vector<vector<int>> adj(n);
        // vector<int> res(n, 0);
        // vector<int> size(n, 0);
        // vector<int> dist(n, 0);

        // vector<vector<int>> graph(n);
        // for (auto &e : edges)
        // {
        //     int u = e[0];
        //     int v = e[1];
        //     graph[u].emplace_back(v);
        //     graph[v].emplace_back(u);
        // }

        // int root = 0;
        // set<int> tree;
        // function<void(int)> make_tree = [&](int u) {
        //     tree.insert(u);
        //     for (int v : graph[u])
        //         if (!tree.count(v))
        //         {
        //             adj[u].emplace_back(v);
        //             make_tree(v);
        //         }
        // };
        // make_tree(root);
        // function<int(int)> dfs = [&](int u) {
        //     size[u] = 1;
        //     for (auto v : adj[u])
        //     {
        //         size[u] += dfs(v);
        //     }
        //     return size[u];
        // };
        // dfs(root);
        // function<int(int)> dfs2 = [&](int u) {
        //     dist[u] = 0;
        //     for (auto v : adj[u])
        //     {
        //         dist[u] += dfs2(v) + size[v];
        //     }
        //     return dist[u];
        // };
        // dfs2(root);
        // res[root] = dist[root];
        // function<void(int)> dfs3 = [&](int u) {
        //     for (auto v : adj[u])
        //     {
        //         res[v] = res[u] + n - 2 * size[v];
        //         dfs3(v);
        //     }
        // };
        // dfs3(root);
        // return res;
    }
};
// @lc code=end

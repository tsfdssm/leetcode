/*
 * @lc app=leetcode.cn id=1916 lang=cpp
 *
 * [1916] 统计为蚁群构筑房间的不同顺序
 */

// @lc code=start
using ll = long long;
class Solution
{
public:
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        int n = prevRoom.size();
        const ll mod = 1e9 + 7;
        ll res = 1;
        vector<ll> g(n);
        for (int i = 2; i < n; ++i)
            res = (res * i) % mod;
        for (int i = 1; i < n; ++i)
            g[i] = i > 1 ? (mod - (mod / i)) * g[mod % i] % mod : 1;
        vector<vector<int>> G(n);
        for (int i = 1; i < n; ++i)
            G[prevRoom[i]].emplace_back(i);
        vector<int> size(n, 0);
        function<void(int)> dfs = [&](int u) {
            size[u] = 1;
            for (int v : G[u])
            {
                dfs(v);
                size[u] += size[v];
            }
        };
        dfs(0);
        for (int i = 1; i < n; ++i)
            res = res * g[size[i]] % mod;
        return res;
    }
};
// @lc code=end

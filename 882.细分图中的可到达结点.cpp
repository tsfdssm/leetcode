/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<vector<int>> adj(n);
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, int> cnt;
        for (auto &e : edges)
        {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
            cnt[e[0] * n + e[1]] = e[2] + 1;
            mp[e[0] * n + e[1]] = {0, e[2]};
        }
        const int inf = 0x3f3f3f3f;
        vector<int> vis(n, 0);
        vector<int> dist(n, inf);
        dist[0] = 0;
        while (1)
        {
            int u = -1;
            int minn = maxMoves;
            for (int i = 0; i < n; ++i)
                if (0 == vis[i])
                    if (dist[i] < minn)
                    {
                        minn = dist[i];
                        u = i;
                    }
            if (-1 == u)
                break;
            vis[u] = 1;
            for (auto v : adj[u])
            {
                int e;
                bool d;
                if (mp.count(u * n + v))
                {
                    e = u * n + v;
                    d = true;
                }
                else
                {
                    e = v * n + u;
                    d = false;
                }

                if (dist[u] + cnt[e] < dist[v])
                    dist[v] = dist[u] + cnt[e];
                if (dist[u] + cnt[e] > maxMoves)
                {
                    int diff = maxMoves - dist[u];
                    if (d)
                    {
                        mp[e].first = min(mp[e].first + diff, mp[e].second);
                    }
                    else
                    {
                        mp[e].second = max(mp[e].second - diff, mp[e].first);
                    }
                }
                else
                {
                    mp[e] = {0, 0};
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            if (dist[i] <= maxMoves)
                ++res;
        for (auto &e : mp)
        {
            res += cnt[e.first] - 1 - max(0, e.second.second - e.second.first);
        }
        return res;
    }
};
// @lc code=end

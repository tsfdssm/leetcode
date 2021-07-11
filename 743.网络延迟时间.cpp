/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
        vector<bool> vis(n + 1, false);

        for (auto vec : times)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u][v] = w;
        }
        unordered_map<int, int> dist;
        dist[k] = 0;
        while (1)
        {
            int u = -1;
            int curDist = inf;
            for (auto &[node, d] : dist)
            {
                if (!vis[node] && dist[node] < curDist)
                {
                    curDist = dist[node];
                    u = node;
                }
            }
            if (-1 == u)
                break;
            vis[u] = true;
            for (int v = 1; v <= n; ++v)
            {
                if (vis[v] || adj[u][v] == inf)
                    continue;
                if (!dist.count(v))
                    dist[v] = inf;
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }
        if (dist.size() < n)
            return -1;
        int res = 0;
        for (auto it = dist.begin(); it != dist.end(); ++it)
        {
            res = max(res, it->second);
        }
        return res;
    }
};
// @lc code=end

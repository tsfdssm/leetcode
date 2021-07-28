/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution
{
public:
    vector<int> vis;
    int n;
    bool dfs(vector<vector<int>> &graph, int u)
    {
        vis[u] = 1;
        for (auto v : graph[u])
        {
            if (2 == vis[v])
                continue;
            if ((vis[v] == 1) || !dfs(graph, v))
            {
                vis[u] = 1;
                return false;
            }
        }
        vis[u] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        n = graph.size();
        vis.resize(n, 0);
        for (int i = 0; i < n; ++i)
            if (0 == vis[i])
                dfs(graph, i);
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (vis[i] == 2)
                res.emplace_back(i);
        return res;
    }
};
// @lc code=end

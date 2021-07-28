/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    int n;
    void dfs(vector<vector<int>> &adj, int cur)
    {
        if (cur == (n - 1))
            res.emplace_back(path);
        for (int i = 0; i < adj[cur].size(); ++i)
        {
            path.emplace_back(adj[cur][i]);
            dfs(adj, adj[cur][i]);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size();
        path.emplace_back(0);
        dfs(graph, 0);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 */

// @lc code=start
class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size();
        int k = initial.size();
        vector<int> vis(n, 0);
        int minn = n + 1;
        int res = -1;
        sort(initial.begin(), initial.end());
        queue<int> q;
        for (int i = 0; i < k; ++i)
        {
            int cnt = k - 1;
            int p = initial[i];
            fill(vis.begin(), vis.end(), 0);
            for (int j = 0; j < k; ++j)
            {
                vis[initial[j]] = 1;
                if (i != j)
                    q.push(initial[j]);
            }
            while (!q.empty())
            {
                auto u = q.front();
                q.pop();
                for (int v = 0; v < n; ++v)
                {
                    if (!vis[v] && 1 == graph[u][v])
                    {
                        cnt++;
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            if (cnt < minn)
            {
                minn = cnt;
                res = p;
            }
        }
        return res;
    }
};
// @lc code=end

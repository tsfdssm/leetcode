/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> res(n, -1);
        for (auto &e : richer)
        {
            adj[e[1]].emplace_back(e[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (adj[i].empty())
            {
                res[i] = i;
                continue;
            }
            q.push(i);
            int minn = i;
            while (!q.empty())
            {
                auto u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (res[v] != -1)
                    {
                        if (quiet[res[v]] < quiet[minn])
                            minn = res[v];
                        continue;
                    }
                    if (quiet[v] < quiet[minn])
                        minn = v;
                    q.push(v);
                }
            }
            res[i] = minn;
        }
        return res;
    }
};
// @lc code=end

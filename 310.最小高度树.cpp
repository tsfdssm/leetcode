/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (1 == n)
            return {0};
        if (2 == n)
            return {0, 1};
        //int n = edges.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            int st = edges[i][0];
            int ed = edges[i][1];
            adj[st].push_back(ed);
            adj[ed].push_back(st);
            ++inDegree[st];
            ++inDegree[ed];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (1 == inDegree[i])
                q.push(i);
        while (n > 2)
        {
            int k = q.size();
            n -= k;
            for (int i = 0; i < k; ++i)
            {
                int tmp = q.front();
                for (int j : adj[tmp])
                {
                    --inDegree[j];
                    if (1 == inDegree[j])
                        q.push(j);
                }
                q.pop();
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

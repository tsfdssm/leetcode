/*
 * @lc app=leetcode.cn id=1583 lang=cpp
 *
 * [1583] 统计不开心的朋友
 */

// @lc code=start
class Solution
{
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        vector<int> mp(n);
        for (auto &e : pairs)
        {
            mp[e[0]] = e[1];
            mp[e[1]] = e[0];
        }
        vector<vector<int>> adj(n, vector<int>(n, n));
        for (int u = 0; u < n; ++u)
            for (int j = 0; j < n - 1; ++j)
            {
                int v = preferences[u][j];
                adj[u][v] = j;
            }
        int res = 0;
        for (int u = 0; u < n; ++u)
        {
            int v = mp[u];
            for (int i = 0; i < adj[u][v]; ++i)
            {
                int t = preferences[u][i];
                if (adj[t][u] < adj[t][mp[t]])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

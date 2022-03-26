/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution
{
public:
    void dfs(int curr, vector<int> &res, vector<vector<int>> &graph)
    {
        // 预留一个避免后续减操作
        bool used[4];
        memset(used, 0, sizeof(used));
        for (int next : graph[curr])
        {
            if (res[next] != 0)
            {
                used[res[next] - 1] = true;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            if (!used[i])
            {
                res[curr] = i + 1;
                break;
            }
        }

        for (int next : graph[curr])
        {
            if (res[next] == 0)
            {
                dfs(next, res, graph);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int> &path : paths)
        {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        // 返回的结果
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (res[i] == 0)
            {
                dfs(i, res, graph);
            }
        }

        return res;
    }
};
// @lc code=end

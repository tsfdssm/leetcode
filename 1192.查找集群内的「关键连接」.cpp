/*
 * @lc app=leetcode.cn id=1192 lang=cpp
 *
 * [1192] 查找集群内的「关键连接」
 *
 * https://leetcode.cn/problems/critical-connections-in-a-network/description/
 *
 * algorithms
 * Hard (52.44%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 11.9K
 * Testcase Example:  '4\n[[0,1],[1,2],[2,0],[1,3]]'
 *
 * 力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。它们之间以「服务器到服务器」点对点的形式相互连接组成了一个内部集群，其中连接
 * connections 是无向的。从形式上讲，connections[i] = [a, b] 表示服务器 a 和 b
 * 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。
 *
 * 「关键连接」 是在该集群中的重要连接，也就是说，假如我们将它移除，便会导致某些服务器无法访问其他服务器。
 *
 * 请你以任意顺序返回该集群内的所有 「关键连接」。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * 输出：[[1,3]]
 * 解释：[[3,1]] 也是正确的。
 *
 * 示例 2:
 *
 *
 * 输入：n = 2, connections = [[0,1]]
 * 输出：[[0,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * n-1 <= connections.length <= 10^5
 * connections[i][0] != connections[i][1]
 * 不存在重复的连接
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &c)
    {
        const int inf = 0x3f3f3f3f;
        vector<int> dfn(n, inf), low(n, inf);
        vector<vector<int>> res;
        vector<vector<int>> adj(n);
        for (auto &e : c)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int d = 0;
        function<void(int, int)> tarjan = [&](int u, int f)
        {
            ++d;
            dfn[u] = d;
            low[u] = d;
            for (auto v : adj[u])
            {
                if (v == f)
                    continue;
                if (dfn[v] == inf)
                {
                    tarjan(v, u);
                }
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    res.push_back({u, v});
            }
            --d;
        };
        for (int i = 0; i < n; ++i)
            if (dfn[i] == inf)
                tarjan(i, -1);
        return res;
    }
};
// @lc code=end

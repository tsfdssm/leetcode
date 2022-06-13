/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 *
 * https://leetcode.cn/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (39.59%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 21K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * 在一个有向图中，节点分别标记为 0, 1, ..., n-1。图中每条边为红色或者蓝色，且存在自环或平行边。
 *
 * red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j]
 * 对表示从节点 i 到节点 j 的蓝色有向边。
 *
 * 返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X
 * 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
 * 输出：[0,1,-1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
 * 输出：[0,1,-1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
 * 输出：[0,-1,-1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
 * 输出：[0,1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
 * 输出：[0,1,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
 * red_edges.length <= 400
 * blue_edges.length <= 400
 * red_edges[i].length == blue_edges[i].length == 2
 * 0 <= red_edges[i][j], blue_edges[i][j] < n
 *
 *
 */

// @lc code=start
class Solution
{
public:
    using pii = pair<int, int>;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        const int inf = 0x3f3f3f3f;
        vector<int> red_dis(n, inf);
        vector<int> blue_dis(n, inf);

        vector<vector<int>> adj_red(n);
        vector<vector<int>> adj_blue(n);
        for (auto &e : redEdges)
        {
            adj_red[e[0]].push_back(e[1]);
        }

        for (auto &e : blueEdges)
        {
            adj_blue[e[0]].push_back(e[1]);
        }

        auto cmp = [&](const pii &a, const pii &b)
        {
            return a.first > b.first;
        };
        priority_queue<pii, vector<pii>, function<bool(const pii &, const pii &)>> p_red(cmp);
        priority_queue<pii, vector<pii>, function<bool(const pii &, const pii &)>> p_blue(cmp);

        p_red.push({0, 0});
        p_blue.push({0, 0});
        while ((!p_red.empty()) || (!p_blue.empty()))
        {
            if (!p_red.empty())
            {
                auto [r_dis, p] = p_red.top();
                p_red.pop();

                if (r_dis < red_dis[p])
                {
                    red_dis[p] = r_dis;
                    for (auto v : adj_blue[p])
                    {
                        if (blue_dis[v] > r_dis + 1)
                        {
                            p_blue.push({r_dis + 1, v});
                        }
                    }
                }
            }
            if (!p_blue.empty())
            {
                auto [b_dis, u] = p_blue.top();
                p_blue.pop();
                if (b_dis < blue_dis[u])
                {
                    blue_dis[u] = b_dis;
                    for (auto v : adj_red[u])
                    {
                        if (red_dis[v] > b_dis + 1)
                            p_red.push({b_dis + 1, v});
                    }
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            res[i] = min(red_dis[i], blue_dis[i]);
            if (inf == res[i])
                res[i] = -1;
        }
        return res;
    }
};
// @lc code=end

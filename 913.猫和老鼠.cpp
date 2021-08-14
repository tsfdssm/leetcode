/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

// @lc code=start
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
class Solution
{
public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        enum
        {
            DRAW = 0,
            MOUSE,
            CAT,
            MAX
        };
        int n = graph.size();
        VVVI color(n, VVI(n, VI(3, 0)));
        VVVI degree(n, VVI(n, VI(3, 0)));
        //0:平,1:mouse,2:cat;
        for (int m = 0; m < n; ++m)
        {
            for (int c = 0; c < n; ++c)
            {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for (int x : graph[c])
                {
                    if (0 == x)
                    {
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
            //for (int v : graph[0])
            //    degree[i][v][1]--;
        }

        queue<tuple<int, int, int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int t = 1; t <= 2; t++)
            {
                color[0][i][t] = MOUSE;
                q.emplace(0, i, t, MOUSE);
                color[i][i][t] = CAT;
                q.emplace(i, i, t, CAT);
                // if (i > 0)
                // {
                //     color[i][i][t] = CAT;
                //     q.emplace(i, i, t, CAT);
                // }
            }
        }
        //queue<VI> q;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int t = 1; t <= 2; ++t)
        //     {
        //         color[0][i][t] = 1;
        //         q.push({0, i, t, 1});
        //         if (i > 0)
        //         {
        //             color[i][i][t] = 2;
        //             q.push({i, i, t, 2});
        //         }
        //     }
        // }
        auto parents = [&](int m, int c, int t) {
            vector<tuple<int, int, int>> res;
            if (t == 2)
            {
                for (auto m1 : graph[m])
                {
                    res.emplace_back(m1, c, 3 - t);
                }
                return res;
            }
            else
            {
                for (auto c1 : graph[c])
                {
                    if (c1 != 0)
                    {
                        res.emplace_back(m, c1, 3 - t);
                    }
                }
                return res;
            }
        };
        // while (!q.empty())
        // {
        //     auto [i, j, t, c] = q.front();
        //     q.pop();
        //     for (auto parent : parents(i, j, t))
        //     {
        //         auto [i1, j1, t1] = parent;
        //         if (color[i1][j1][t1] == DRAW)
        //         {
        //             if (t1 == c)
        //             {
        //                 color[i1][j1][t1] = c;
        //                 q.emplace(i1, j1, t1, c);
        //             }
        //             else
        //             {
        //                 degree[i1][j1][t1]--;
        //                 if (degree[i1][j1][t1] == 0)
        //                 {
        //                     color[i1][j1][t1] = c;
        //                     q.emplace(i1, j1, t1, c);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return color[1][2][1];
        while (!q.empty())
        {
            auto [i, j, t, c] = q.front();
            //auto &cur = q.front();
            //int i = cur[0], j = cur[1], t = cur[2], c = cur[3];
            q.pop();
            for (auto parent : parents(i, j, t))
            {
                auto [i1, j1, t1] = parent;
                //int i1 = parent[0], j1 = parent[1], t1 = parent[2];
                if (DRAW == color[i1][j1][t1])
                {
                    if (c == t1)
                    {
                        color[i1][j1][t1] = c;
                        q.emplace(i1, j1, t1, c);
                    }
                    else
                    {
                        degree[i1][j1][t1]--;
                        if (0 == degree[i1][j1][t1])
                        {
                            color[i1][j1][t1] = c;
                            q.emplace(i1, j1, t1, c);
                        }
                    }
                }
            }
        }
        return color[1][2][1];
        //     if (t == 2)
        //     {
        //         for (int i1 : graph[i])
        //         {
        //             if (c == 1)
        //             {
        //                 color[i1][j][1] = 1;
        //                 q.push({i1, j, 1, 1});
        //             }
        //             else
        //             {
        //                 degree[i1][j][1]--;
        //                 if (0 == degree[i1][j][1])
        //                 {
        //                     color[i1][j][1] = 2;
        //                     q.push({i1, j, 1, 2});
        //                 }
        //             }
        //         }
        //     }
        //     else
        //     {
        //         for (int j1 : graph[j])
        //         {
        //             if (c == 2)
        //             {
        //                 color[i][j1][2] = 2;
        //                 q.push({i, j1, 2, 2});
        //             }
        //             else
        //             {
        //                 degree[i][j1][2]--;
        //                 if (0 == degree[i][j][2])
        //                 {
        //                     color[i][j1][2] = 1;
        //                     q.push({i, j1, 2, 1});
        //                 }
        //             }
        //         }
        //     }
    }
    // VVI parents(VVI &graph, int m, int c, int t)
    // {
    //     VVI res;
    //     if (2 == t)
    //     {
    //         for (int m2 : graph[m])
    //             res.push_back({m2, c, 3 - t});
    //     }
    //     else
    //     {
    //         for (int c2 : graph[c])
    //             if (c2 > 0)
    //                 res.push_back({m, c2, 3 - t});
    //     }
    //     return res;
    // }
};
// @lc code=end

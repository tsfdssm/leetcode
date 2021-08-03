/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> father;
    UnionFind(int n)
    {
        father.resize(n);
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }

    int find(int x)
    {
        if (father[x] == x)
            return x;
        return father[x] = find(father[x]);
    }

    void merge(int x, int y)
    {
        if (find(x) == find(y))
            return;
        father[find(y)] = find(x);
    }
};
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        // if (target == source)
        //     return 0;
        // int n = routes.size();
        // unordered_set<int> seen;
        // seen.insert(source);

        // vector<int> vis(n, 0);
        // vector<unordered_set<int>> all(n);

        // UnionFind uf(1e6);
        // for (int i = 0; i < n; ++i)
        //     for (int d : routes[i])
        //     {
        //         all[i].insert(d);
        //         uf.merge(d, routes[i][0]);
        //     }
        // if (uf.find(source) != uf.find(target))
        //     return -1;
        // queue<int> q;
        // q.push(source);

        // int cnt = 1;
        // while (!q.empty())
        // {
        //     int len = q.size();
        //     for (int i = 0; i < len; ++i)
        //     {
        //         auto cur = q.front();
        //         q.pop();
        //         for (int j = 0; j < n; ++j)
        //         {
        //             if (vis[j])
        //                 continue;
        //             if (!all[j].count(cur))
        //                 continue;
        //             vis[j] = 1;
        //             if (all[j].count(target))
        //                 return cnt;
        //             for (int d : all[j])
        //             {
        //                 if (!seen.count(d))
        //                 {
        //                     seen.insert(d);
        //                     q.push(d);
        //                 }
        //             }
        //         }
        //     }
        //     ++cnt;
        // }
        // return -1;
    }
};
// @lc code=end

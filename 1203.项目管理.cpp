/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 *
 * https://leetcode.cn/problems/sort-items-by-groups-respecting-dependencies/description/
 *
 * algorithms
 * Hard (61.72%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 20.9K
 * Testcase Example:  '8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3,6],[],[],[]]'
 *
 * 有 n 个项目，每个项目或者不属于任何小组，或者属于 m 个小组之一。group[i] 表示第 i 个项目所属的小组，如果第 i
 * 个项目不属于任何小组，则 group[i] 等于 -1。项目和小组都是从零开始编号的。可能存在小组不负责任何项目，即没有任何项目属于这个小组。
 *
 * 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
 *
 *
 * 同一小组的项目，排序后在列表中彼此相邻。
 * 项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i
 * 个项目左侧）应该完成的所有项目。
 *
 *
 * 如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3,6],[],[],[]]
 * 输出：[6,3,4,1,5,2,0,7]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3],[],[4],[]]
 * 输出：[]
 * 解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * group.length == beforeItems.length == n
 * -1
 * 0
 * 0
 * i != beforeItems[i][j]
 * beforeItems[i] 不含重复元素
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> top_sort(vector<int> &degree, vector<vector<int>> &adj, vector<int> &ids)
    {
        queue<int> q;
        for (int i : ids)
        {
            if (0 == degree[i])
                q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u])
            {
                degree[v]--;
                if (0 == degree[v])
                    q.push(v);
            }
        }
        if (res.size() != ids.size())
            return {};
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &be)
    {

        int leftID = m;
        for (int i = 0; i < n; ++i)
            if (-1 == group[i])
                group[i] = leftID++;

        int total = leftID;
        vector<vector<int>> all_group2peo(total);
        vector<int> all_groupID(total);

        for (int i = 0; i < n; ++i)
            all_group2peo[group[i]].push_back(i);
        for (int i = 0; i < total; ++i)
            all_groupID[i] = i;

        vector<int> degree(n);
        vector<vector<int>> adj(n);

        vector<int> degree_g(total);
        vector<vector<int>> adj_g(total);

        for (int u = 0; u < n; ++u)
        {
            for (int v : be[u])
            {
                if (group[v] == group[u])
                {
                    adj[v].push_back(u);
                    degree[u]++;
                }
                else
                {
                    adj_g[group[v]].push_back(group[u]);
                    degree_g[group[u]]++;
                }
            }
        }

        vector<int> group_seq = top_sort(degree_g, adj_g, all_groupID);
        if (0 == group_seq.size())
            return {};
        vector<int> res;
        for (int g : group_seq)
        {
            if (all_group2peo[g].empty())
                continue;
            auto tmp = top_sort(degree, adj, all_group2peo[g]);
            if (tmp.empty())
                return {};
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};
// @lc code=end

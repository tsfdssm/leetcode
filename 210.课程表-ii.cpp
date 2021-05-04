/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> in;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>> &pre)
    {
        edges.resize(numCourses);
        in.resize(numCourses);
        for (const auto &info : pre)
        {
            edges[info[1]].push_back(info[0]);
            ++in[info[0]];
        }
        queue<int> q;
        for (int i = 0; i < in.size(); ++i)
        {
            if (0 == in[i])
                q.push(i);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto &tmp : edges[u])
            {
                --in[tmp];
                if (0 == in[tmp])
                    q.push(tmp);
            }
        }
        if (numCourses != res.size())
            return {};
        return res;
    }
};
// @lc code=end

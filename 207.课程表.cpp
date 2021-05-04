/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_set<int> vis;
        vector<vector<int>> adj(numCourses);
        for (const auto &vec : prerequisites)
        {
            adj[vec[0]].push_back(vec[1]);
        }
        int res = -1;
        while (res < numCourses)
        {
            res = vis.size();
            for (int i = 0; i < numCourses; ++i)
            {
                if (1 == vis.count(i))
                    continue;
                bool flag = true;
                for (int j = 0; j < adj[i].size(); ++j)
                    if (0 == vis.count(adj[i][j]))
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                    vis.insert(i);
            }
            if (res == vis.size())
                break;
        }
        if (res == numCourses)
            return true;
        else
        {
            return false;
        }
    }
};
// @lc code=end

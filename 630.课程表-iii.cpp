/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int res = 0;
        sort(courses.begin(), courses.end(), [&](const auto &a, const auto &b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); });
        priority_queue<int, vector<int>, less<int>> q;
        int time = 0;
        for (const auto &cur : courses)
        {
            if (cur[0] + time <= cur[1])
            {
                q.push(cur[0]);
                time += cur[0];
            }
            else if (!q.empty() && cur[0] < q.top())
            {
                time += cur[0] - q.top();
                q.pop();
                q.push(cur[0]);
            }
            else
            {
            }
        }
        return q.size();
    }
};
// @lc code=end

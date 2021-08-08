/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

// @lc code=start
class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        double res = INT_MAX;
        int len = quality.size(), p = 0;
        vector<pair<double, int>> m(len);
        for (int i = 0; i < len; ++i)
            m[i] = {(double)wage[i] / quality[i], quality[i]};
        sort(m.begin(), m.end());
        priority_queue<int> q;
        for (auto &x : m)
        {
            if (q.size() < k)
            {
                q.push(x.second);
                p += x.second;
            }
            if (q.size() == k)
            {
                res = min(res, x.first * p);
                p -= q.top();
                q.pop();
            }
        }
        return res;
    }
};
// @lc code=end

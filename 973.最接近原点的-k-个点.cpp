/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto &p : points)
        {
            int x = p[0];
            int y = p[1];
            q.push({x, y});
            if (q.size() > k)
                q.pop();
        }
        vector<vector<int>> res;
        while (!q.empty())
        {
            auto [x, y] = q.top();
            res.push_back({x, y});
            q.pop();
        }
        return res;
    }
};
// @lc code=end

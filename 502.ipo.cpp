/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
struct Proj
{
    int cap;
    int pro;
};
bool operator<(const Proj &a, const Proj &b)
{
    return a.pro < b.pro;
}
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<Proj> vec(n);
        for (int i = 0; i < n; ++i)
        {
            vec[i].cap = capital[i];
            vec[i].pro = profits[i];
        }
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) { return a.cap < b.cap; });
        priority_queue<Proj> q;
        int res = w;
        int st = 0;
        for (int i = 0; i < k; ++i)
        {
            while (st < n && vec[st].cap <= res)
            {
                q.push(vec[st]);
                ++st;
            }
            if (q.empty())
                break;
            res += q.top().pro;
            q.pop();
        }
        return res;
    }
};
// @lc code=end

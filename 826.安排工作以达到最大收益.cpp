/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = profit.size();
        vector<pair<int, int>> all;
        for (int i = 0; i < n; ++i)
        {
            all.push_back({difficulty[i], profit[i]});
        }
        sort(all.begin(), all.end(), [](const auto &a, const auto &b) { return a.first < b.first || a.first == b.first && a.second > b.second; });
        sort(difficulty.begin(), difficulty.end());
        vector<int> pre(n, 0);
        int maxn = 0;
        for (int i = 0; i < n; ++i)
        {
            maxn = max(maxn, all[i].second);
            pre[i] = maxn;
        }
        int res = 0;
        int m = worker.size();
        for (int i = 0; i < m; ++i)
        {
            int idx = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin() - 1;
            if (idx < 0)
                continue;
            res += pre[idx];
        }
        return res;
    }
};
// @lc code=end

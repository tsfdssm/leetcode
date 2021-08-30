/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> cnt(n, 0);
        vector<vector<int>> all(n);
        for (auto &e : trust)
        {
            cnt[e[1] - 1]++;
            all[e[0] - 1].emplace_back(e[1] - 1);
        }
        set<int> st;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == n - 1 && all[i].size() == 0)
                st.insert(i);
        if (st.size() == 1)
            return *st.begin() + 1;
        return -1;
    }
};
// @lc code=end

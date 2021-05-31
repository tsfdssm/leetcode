/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> stk;

    void dfs(const string &s)
    {
        while (vec.count(s) && !vec[s].empty())
        {
            string tmp = vec[s].top();
            vec[s].pop();
            dfs(tmp);
        }
        stk.emplace_back(s);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto it : tickets)
            vec[it[0]].push(it[1]);
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }
};
// @lc code=end

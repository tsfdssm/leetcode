/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<string> dp;
    unordered_map<string, vector<char>> mp;
    bool dfs(int row, int col)
    {
        if (row == col)
        {
            row--;
            col = 0;
        }
        if (row == 0)
            return true;
        for (char c : mp[dp[row].substr(col, 2)])
        {
            dp[row - 1].push_back(c);
            if (dfs(row, col + 1))
                return true;
            dp[row - 1].pop_back();
        }
        return false;
    }
    bool pyramidTransition(const string &bottom, vector<string> &allowed)
    {
        int n = bottom.size();
        for (string &s : allowed)
        {
            mp[s.substr(0, 2)].emplace_back(s[2]);
        }
        dp.resize(n);
        dp[n - 1] = bottom;
        return dfs(n - 1, 0);
    }
};
// @lc code=end

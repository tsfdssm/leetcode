/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> dp;
    vector<vector<string>> res;
    vector<string> tmp;

    void dfs(const string &s, int i, int n)
    {
        if (i == n)
        {
            res.emplace_back(tmp);
            return;
        }
        for (int j = i; j < n; ++j)
        {
            if (dp[i][j])
            {
                tmp.emplace_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, n);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        if (0 == n)
            return res;
        dp.assign(n, vector<int>(n, true));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
        dfs(s, 0, n);
        return res;
    }
};
// @lc code=end

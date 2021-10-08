/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution
{
public:
    bool cmp(const string &s, const string &p)
    {
        int n = p.size();
        int idx = 0;
        for (char c : s)
        {
            if (idx < n && (p[idx] == c))
            {
                ++idx;
            }
            else if ('A' <= c && c <= 'Z')
                return false;
        }
        return idx == n;
    }
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        int m = queries.size();
        vector<bool> res(m, false);
        for (int i = 0; i < m; ++i)
        {
            res[i] = cmp(queries[i], pattern);
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;

    void dfs(string &s, int u, string res, int cnt, int l, int r)
    {
        if (u == s.size())
        {
            if (0 == cnt)
                ans.emplace_back(res);
            return;
        }
        if ('(' == s[u])
        {
            int k = u;
            while (k < s.size() && '(' == s[k])
                ++k;
            l -= k - u;
            for (int i = k - u; i >= 0; --i)
            {
                if (l >= 0)
                    dfs(s, k, res, cnt, l, r);
                res += '(';
                ++cnt;
                ++l;
            }
        }
        else if (')' == s[u])
        {
            int k = u;
            while (k < s.size() && s[k] == ')')
                ++k;
            r -= k - u;
            for (int i = k - u; i >= 0; --i)
            {
                if (cnt >= 0 && r >= 0)
                    dfs(s, k, res, cnt, l, r);
                res += ')';
                --cnt;
                ++r;
            }
        }
        else
            dfs(s, u + 1, res + s[u], cnt, l, r);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int l = 0, r = 0;
        for (auto c : s)
        {
            if ('(' == c)
                ++l;
            else if (')' == c)
            {
                if (l <= 0)
                    ++r;
                else
                    --l;
            }
        }
        dfs(s, 0, "", 0, l, r);
        return ans;
    }
};
// @lc code=end

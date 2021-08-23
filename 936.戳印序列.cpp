/*
 * @lc app=leetcode.cn id=936 lang=cpp
 *
 * [936] 戳印序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> ans;
        int cnt = 0;

        int n = target.size();
        int m = stamp.size();
        set<int> s;
        for (int i = 0; i <= n - m; ++i)
            s.insert(i);
        while (cnt < n)
        {
            bool have = false;
            for (auto it = s.begin(); it != s.end();)
            {
                int res = match(target, stamp, *it);
                auto t = it;
                ++t;
                if (res)
                {
                    have = true;
                    cnt += res;
                    ans.push_back(*it);
                    s.erase(it);
                }
                it = t;
            }
            if (!have)
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int match(string &s, string &p, int base)
    {
        int res = 0;
        for (int i = 0; i < p.size(); ++i)
            if (s[i + base] != '?' && s[i + base] != p[i])
                return 0;
        for (int i = 0; i < p.size(); ++i)
            if (s[i + base] != '?')
            {
                s[i + base] = '?';
                ++res;
            }
        return res;
    }
};
// @lc code=end

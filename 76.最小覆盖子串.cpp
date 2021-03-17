/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, int> tar, cnt;
    bool check()
    {
        for (const auto &p : tar)
            if (cnt[p.first] < p.second)
                return false;
        return true;
    }
    string minWindow(string s, string t)
    {
        for (const auto &c : t)
            ++tar[c];
        int l = 0, r = -1;
        int len = INT_MAX, resL = -1;
        while (r < int(s.size()))
        {
            if (tar.find(s[++r]) != tar.end())
                ++cnt[s[r]];
            while (check())
            {
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    resL = l;
                }
                if (tar.find(s[l]) != tar.end())
                    --cnt[s[l]];
                ++l;
            }
        }
        return (resL == -1) ? string() : s.substr(resL, len);
    }
};
// @lc code=end

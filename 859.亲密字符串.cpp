/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        int n = s.size();
        int res = 0;
        vector<int> cnt(26, 0);
        vector<int> e1, e2;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != goal[i])
            {
                ++res;
                e1.emplace_back(s[i]);
                e2.emplace_back(goal[i]);
            }
            cnt[s[i] - 'a']++;
            if (res > 2)
                return false;
        }
        if (0 == res)
            return *max_element(cnt.begin(), cnt.end()) >= 2;
        if (1 == res)
            return false;
        reverse(e1.begin(), e1.end());
        return e1 == e2;
    }
};
// @lc code=end

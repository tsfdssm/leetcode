/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(const string &s)
    {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        auto idx = max_element(cnt.begin(), cnt.end());
        auto maxn = *idx;
        if (n % 2 == 0 && maxn > (n / 2))
            return "";
        if (n % 2 == 1 && maxn > (n / 2 + 1))
            return "";
        string res(n, 'a');
        for (int i = 0; i < n; i += 2)
        {
            res[i] = idx - cnt.begin() + 'a';
            (*idx)--;
            if ((*idx) == 0)
            {
                idx = max_element(cnt.begin(), cnt.end());
            }
        }
        for (int i = 1; i < n; i += 2)
        {
            res[i] = idx - cnt.begin() + 'a';
            (*idx)--;
            if ((*idx) == 0)
            {
                idx = max_element(cnt.begin(), cnt.end());
            }
        }
        return res;
    }
};
// @lc code=end

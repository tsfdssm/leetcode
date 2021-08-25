/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> pos(26);
        for (int i = 0; i < 26; ++i)
            pos[order[i] - 'a'] = i;
        int n = words.size();
        auto check = [&](const string &a, const string &b) {
            int m = a.size();
            int n = b.size();
            int t = min(m, n);
            for (int i = 0; i < t; ++i)
            {
                if (a[i] == b[i])
                    continue;
                return pos[a[i] - 'a'] < pos[b[i] - 'a'];
            }
            return m <= n;
        };
        for (int i = 1; i < n; ++i)
        {
            if (!check(words[i - 1], words[i]))
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(const string &a, const string &b)
    {
        if (a.size() != b.size() - 1)
            return false;
        int i = 0;
        for (int j = 0; j < b.size() && i < a.size(); ++j)
        {
            if (a[i] == b[j])
            {
                ++i;
            }
        }
        return i == a.size();
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        int n = words.size();
        vector<int> d(n);
        for (int i = 0; i < n; ++i)
            d[i] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (isMatch(words[j], words[i]))
                    d[i] = max(d[i], d[j] + 1);
        return *max_element(d.begin(), d.end());
    }
};
// @lc code=end

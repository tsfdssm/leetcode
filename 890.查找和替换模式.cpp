/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// @lc code=start
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> res;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for (string &s : words)
        {
            int n = s.size();
            mp1.clear();
            mp2.clear();
            int idx = 0;
            while (idx < n)
            {
                if (!mp1.count(s[idx]))
                {
                    mp1[s[idx]] = pattern[idx];
                }
                else if (mp1[s[idx]] != pattern[idx])
                {
                    break;
                }

                if (!mp2.count(pattern[idx]))
                {
                    mp2[pattern[idx]] = s[idx];
                }
                else if (mp2[pattern[idx]] != s[idx])
                {
                    break;
                }
                ++idx;
            }
            if (n == idx)
                res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

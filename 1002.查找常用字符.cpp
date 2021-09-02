/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> cnt(26, 100);
        for (string &s : words)
        {
            vector<int> tmp(26, 0);
            for (char c : s)
                tmp[c - 'a']++;
            for (int j = 0; j < 26; ++j)
                cnt[j] = min(cnt[j], tmp[j]);
        }

        vector<string> res;
        for (int i = 0; i < 26; ++i)
        {
            string cur;
            cur += 'a' + i;
            for (int j = 0; j < cnt[i]; ++j)
                res.emplace_back(cur);
        }
        return res;
    }
};
// @lc code=end

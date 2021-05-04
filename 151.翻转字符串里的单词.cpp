/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> res;
        for (int i = 0; i < s.size();)
        {
            if (' ' == s[i])
            {
                ++i;
                continue;
            }
            int j = i;
            while (j < s.size() && s[j] != ' ')
                ++j;
            string tmp = string(s.begin() + i, s.begin() + j);
            res.emplace_back(tmp);
            i = j;
        }
        reverse(res.begin(), res.end());
        string ans;
        for (const auto &str : res)
        {
            ans += ans.empty() ? str : " " + str;
        }
        return ans;
    }
};
// @lc code=end

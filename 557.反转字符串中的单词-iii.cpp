/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(const string &s)
    {
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
                continue;
            int j = i;
            while (j < n && s[j] != ' ')
                ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};
// @lc code=end

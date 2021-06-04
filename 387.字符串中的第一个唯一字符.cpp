/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> chars(26, 0);
        for (char c : s)
            chars[c - 'a']++;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (chars[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if ('A' <= s[i] && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        return s;
    }
};
// @lc code=end

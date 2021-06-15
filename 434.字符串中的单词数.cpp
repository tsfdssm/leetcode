/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (' ' != s[i])
            {
                res++;
                while (i < n && ' ' != s[i])
                    ++i;
            }
        }
        return res;
    }
};
// @lc code=end

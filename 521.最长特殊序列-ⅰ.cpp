/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        int m = a.size();
        int n = b.size();
        if (m != n)
            return max(m, n);
        if (a != b)
            return m;
        return -1;
    }
};
// @lc code=end

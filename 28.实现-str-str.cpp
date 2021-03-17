/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int L = needle.size();
        int n = haystack.size() - needle.size();
        for (int i = 0; i <= n; i++)
        {
            if (haystack.substr(i, L) == needle)
                return i;
        }
        return -1;
    }
};
// @lc code=end

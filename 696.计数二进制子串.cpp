/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(const string &s)
    {
        int n = s.size();
        int last = 0;
        int res = 0;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && s[j] == s[i])
                ++j;
            int len = j - i;
            res += min(last, len);
            last = len;
            i = j;
        }
        return res;
    }
};
// @lc code=end

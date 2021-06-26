/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        int l = 0, r = k;
        while (r < n)
        {
            reverse(s.begin() + l, s.begin() + r);
            l += 2 * k;
            r += 2 * k;
        }
        if (l < n)
        {
            r = min(r, n);
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};
// @lc code=end

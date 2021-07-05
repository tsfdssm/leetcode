/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return isPal(s.substr(l, r - l)) || isPal(s.substr(l + 1, r - l));
            }
            ++l;
            --r;
        }
        return true;
    }

    bool isPal(const string &s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};
// @lc code=end

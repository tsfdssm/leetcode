/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (0 == s.size())
            return true;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while (i <= j && !(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'))
                ++i;
            while (i <= j && !(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z' || s[j] >= '0' && s[j] <= '9'))
                --j;
            if (i >= j)
                break;
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 'a' - 'A';
            if (s[j] >= 'A' && s[j] <= 'Z')
                s[j] = s[j] + 'a' - 'A';
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
// @lc code=end

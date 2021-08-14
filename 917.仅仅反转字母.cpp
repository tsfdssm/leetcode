/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && (!isChar(s[l])))
                ++l;
            while (l < r && (!isChar(s[r])))
                --r;
            if (l == r)
                break;
            swap(s[l], s[r]);
            ++l;
            --r;
        }
        return s;
    }

    inline bool isChar(char c)
    {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
    }
};
// @lc code=end

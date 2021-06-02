/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            while (l < r && !isVowel(s[l]))
                ++l;
            while (r > l && !isVowel(s[r]))
                --r;
            if (l >= r)
                break;
            swap(s[l], s[r]);
            ++l;
            --r;
        }
        return s;
    }
    inline bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=848 lang=cpp
 *
 * [848] 字母移位
 */

// @lc code=start
class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int n = shifts.size();
        shifts[n - 1] %= 26;
        for (int i = n - 2; i >= 0; --i)
        {
            shifts[i] += shifts[i + 1];
            shifts[i] %= 26;
        }

        for (int i = 0; i < n; ++i)
        {
            int c = s[i] - 'a';
            c += shifts[i];
            c %= 26;
            s[i] = c + 'a';
        }
        return s;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        if (n <= 1)
            return true;
        int flag = isbig(word[1]) ? true : false;
        if (flag && !isbig(word[0]))
            return false;
        for (int i = 2; i < n; ++i)
        {
            if (flag && !isbig(word[i]) || !flag && isbig(word[i]))
            {
                return false;
            }
        }
        return true;
    }

    inline bool isbig(char c)
    {
        return 'A' <= c && c <= 'Z';
    }
};
// @lc code=end

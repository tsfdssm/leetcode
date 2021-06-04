/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int a[26];
        memset(a, 0, 26 * sizeof(int));
        //vector<int> a(26, 0);
        for (char c : s)
            a[c - 'a']++;
        for (char c : t)
        {
            a[c - 'a']--;
            if (0 > a[c - 'a'])
                return c;
        }
        return ' ';
    }
};
// @lc code=end

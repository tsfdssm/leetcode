/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;

        bool flag = false;

        for (char c : s)
            mp[c]++;

        int res = 0;
        for (const auto &it : mp)
        {
            if (0 == it.second % 2)
                res += it.second;
            else
            {
                res += it.second - 1;
                flag = true;
            }
        }
        if (flag)
            ++res;
        return res;
    }
};
// @lc code=end

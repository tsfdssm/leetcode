/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int k = s1.size();
        int n = s2.size();
        if (k > n)
            return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (char c : s1)
            v1[c - 'a']++;
        for (int i = 0; i < k; ++i)
            v2[s2[i] - 'a']++;
        if (v1 == v2)
            return true;
        for (int i = k; i < n; ++i)
        {
            v2[s2[i - k] - 'a']--;
            v2[s2[i] - 'a']++;
            if (v1 == v2)
                return true;
        }
        return false;
    }
};
// @lc code=end

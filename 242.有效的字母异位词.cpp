/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : t)
        {
            auto it = mp.find(c);
            if (it == mp.end() || it->second <= 0)
                return false;
            it->second--;
        }
        for (auto i : mp)
            if (i.second != 0)
                return false;
        return true;
    }
};
// @lc code=end

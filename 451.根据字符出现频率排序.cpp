/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        vector<pair<char, int>> vec;
        for (char c : s)
            mp[c]++;
        for (const auto &it : mp)
            vec.emplace_back(it);
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) -> bool { return a.second > b.second; });

        string res;
        for (const auto &it : vec)
        {
            res += string(it.second, it.first);
        }
        return res;
    }
};
// @lc code=end

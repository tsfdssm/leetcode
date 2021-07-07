/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        vector<string> vec;
        for (const auto &s : words)
            mp[s]++;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            vec.emplace_back(it->first);
        sort(vec.begin(), vec.end(), [&](const auto &a, const auto &b) { return mp[a] > mp[b] || mp[a] == mp[b] && a < b; });
        return vector<string>(vec.begin(), vec.begin() + k);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        unordered_map<string, int> mp;
        for (int i = 0; i < (int)s.size() - 9; ++i)
        {
            mp[s.substr(i, 10)]++;
        }
        vector<string> res;
        // for (const auto it = mp.begin(), it != mp.end(); ++it)
        //     if (it->first > 1)
        //         res.emplace_back(str);
        for (const auto &str : mp)
            if (str.second > 1)
                res.emplace_back(str.first);
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> res(n, "");
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[score[i]] = i;
        int i = 0;
        for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it, ++i)
        {
            if (i >= 3)
                res[it->second] = to_string(i + 1);
            else if (i == 0)
                res[it->second] = "Gold Medal";
            else if (i == 1)
                res[it->second] = "Silver Medal";
            else
                res[it->second] = "Bronze Medal";
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        map<int, int> mp;

        for (int i = 0; i < n; ++i)
        {
            int k = 0;
            int val = words[i].size();
            for (int j = 0; j < words[i].size(); ++j)
            {
                k |= 1 << (words[i][j] - 'a');
            }
            if (0 == mp.count(k))
            {
                mp[k] = i;
            }
            else
            {
                int index = mp[k];
                if (words[index].size() < words[i].size())
                    mp[k] = i;
            }
        }
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            for (auto it2 = it; it2 != mp.end(); ++it2)
            {
                if ((it->first & it2->first) == 0)
                    res = max(res, (int)(words[it->second].size() * words[it2->second].size()));
            }
        return res;
    }
};
// @lc code=end

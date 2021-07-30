/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> mp;
        for (string s : cpdomains)
        {
            int n = s.size();
            int i = 0;
            while (i < n && s[i] != ' ')
                ++i;
            int num = stoi(s.substr(0, i));
            ++i;
            while (i < n)
            {
                mp[s.substr(i, n - i)] += num;
                int j = i + 1;
                while (j < n && s[j] != '.')
                    ++j;
                i = j + 1;
            }
        }
        vector<string> res;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            res.emplace_back(to_string(it->second) + " " + it->first);
        }
        return res;
    }
};
// @lc code=end

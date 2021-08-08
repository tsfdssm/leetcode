/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        int n = s.size();
        int k = indices.size();

        string res;

        map<int, pair<string, string>> mp;
        for (int i = 0; i < k; ++i)
            mp[indices[i]] = make_pair(sources[i], targets[i]);

        auto it = mp.begin();
        res += s.substr(0, it->first);

        for (; it != mp.end(); ++it)
        {
            string tmp = s.substr(it->first, it->second.first.size());
            int last = (next(it) == mp.end()) ? n : next(it)->first;
            if (tmp == it->second.first)
            {
                res += it->second.second;
                res += s.substr(it->first + it->second.first.size(), last - (it->first + it->second.first.size()));
            }
            else
            {
                res += s.substr(it->first, last - it->first);
            }
        }
        return res;
    }
};
// @lc code=end

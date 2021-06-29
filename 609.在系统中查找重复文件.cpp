/*
 * @lc app=leetcode.cn id=609 lang=cpp
 *
 * [609] 在系统中查找重复文件
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> mp;
        int n = paths.size();
        for (int i = 0; i < n; ++i)
        {
            const string &path = paths[i];
            int len = path.size();
            int idx = 0;
            while (path[idx] != ' ')
                ++idx;
            string dir = path.substr(0, idx) + '/';
            ++idx;
            for (int j = idx; j < len; ++j)
            {
                if (path[j] == ' ')
                    continue;
                int k = j;
                while (k < len && path[k] != '(')
                    ++k;
                string file = path.substr(j, k - j);
                k++;
                j = k;
                while (k < len && path[k] != ')')
                    ++k;
                string content = path.substr(j, k - j);
                if (mp.count(content))
                {
                    mp[content].emplace_back(dir + file);
                }
                else
                {
                    mp.insert({content, {dir + file}});
                }
                j = k;
            }
        }
        vector<vector<string>> res;
        for (const auto &it : mp)
            if (it.second.size() > 1)
                res.emplace_back(it.second);
        return res;
    }
};
// @lc code=end

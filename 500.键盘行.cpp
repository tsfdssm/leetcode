/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> dict;
        dict.push_back("qwertyuiop");
        dict.push_back("asdfghjkl");
        dict.push_back("zxcvbnm");
        vector<unordered_set<char>> vec(3);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < dict[i].size(); ++j)
                vec[i].insert(dict[i][j]);

        vector<string> res;
        for (const auto &s : words)
        {
            int c = s[0];
            if ('A' <= c && c <= 'Z')
                c += 'a' - 'A';
            int idx = 0;
            for (int i = 0; i < 3; ++i)
                if (vec[i].count(c))
                {
                    idx = i;
                    break;
                }
            bool ok = true;
            for (int i = 1; i < s.size(); ++i)
            {
                char cur = s[i];
                if ('A' <= cur && cur <= 'Z')
                    cur += 'a' - 'A';
                if (!vec[idx].count(cur))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

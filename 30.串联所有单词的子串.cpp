/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.size() == 0)
            return res;
        if (words[0].size() == 0)
            return res;

        int n = words.size();
        int m = words[0].size();
        int l = m * n;
        if (s.size() < l)
            return res;
        unordered_map<string, int> map1;
        for (string s : words)
        {
            map1[s]++;
        }

        unordered_map<string, int> map2;

        for (int i = 0; i <= s.size() - l; i++)
        {
            bool flag = true;
            map2.clear();
            for (int j = 0; j < n; j++)
            {
                string tmp = s.substr(i + j * m, m);
                if (map1.find(tmp) == map1.end())
                {
                    flag = false;
                    break;
                }
                map2[tmp]++;
                if (map1[tmp] < map2[tmp])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

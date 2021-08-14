/*
 * @lc app=leetcode.cn id=916 lang=cpp
 *
 * [916] 单词子集
 */

// @lc code=start
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> cntb(26, 0);
        vector<int> tmp(26, 0);
        for (string &s : words2)
        {
            fill(tmp.begin(), tmp.end(), 0);
            for (char c : s)
                tmp[c - 'a']++;
            for (int i = 0; i < 26; ++i)
                cntb[i] = max(cntb[i], tmp[i]);
        }

        vector<string> res;
        for (string &s : words1)
        {
            fill(tmp.begin(), tmp.end(), 0);
            for (char c : s)
                tmp[c - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; ++i)
                if (tmp[i] < cntb[i])
                {
                    flag = false;
                    break;
                }
            if (flag)
                res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

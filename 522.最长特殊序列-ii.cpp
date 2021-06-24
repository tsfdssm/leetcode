/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
class Solution
{
public:
    bool isSubStr(const string &a, const string &b)
    {
        int i = 0;
        for (char c : b)
        {
            if (i < a.size() && a[i] == c)
                ++i;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string> &strs)
    {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [](const string &a, const string &b) { return a.size() > b.size(); });
        for (int i = 0; i < n; ++i)
        {
            bool isSub = false;
            for (int j = 0; j < n && strs[j].size() >= strs[i].size(); ++j)
            {
                if (i != j && isSubStr(strs[i], strs[j]))
                {
                    isSub = true;
                    break;
                }
            }
            if (!isSub)
                return strs[i].size();
        }
        return -1;
    }
};
// @lc code=end

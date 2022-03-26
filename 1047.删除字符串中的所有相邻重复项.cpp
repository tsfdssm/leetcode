/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (!res.empty() && (res.back() == c))
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};
// @lc code=end

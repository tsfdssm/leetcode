/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i)
            res[i] = i;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'I')
                continue;
            int j = i + 1;
            while (j < n && s[j] == 'D')
                ++j;
            reverse(res.begin() + i, res.begin() + j + 1);
            i = j - 1;
        }
        return res;
    }
};
// @lc code=end

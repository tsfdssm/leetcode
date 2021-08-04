/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution
{
public:
    int uniqueLetterString(string s)
    {
        int n = s.size();
        vector<vector<int>> cnt(26);
        for (int i = 0; i < n; ++i)
            cnt[s[i] - 'A'].emplace_back(i);

        long long res = 0;
        for (auto vec : cnt)
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                int pre = (i == 0) ? -1 : vec[i - 1];
                int nxt = (i == vec.size() - 1) ? n : vec[i + 1];
                res += (vec[i] - pre) * (nxt - vec[i]);
            }
        }
        return (int)(res % (1000000000 + 7));
    }
};
// @lc code=end

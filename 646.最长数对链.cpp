/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [&](const auto &a, const auto &b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); });
        int time = pairs[0][1];
        int res = 1;
        for (int i = 1; i < n; ++i)
        {
            if (pairs[i][0] <= time)
                continue;
            res++;
            time = pairs[i][1];
        }
        return res;
    }
};
// @lc code=end

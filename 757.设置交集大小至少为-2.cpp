/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        if (1 == intervals.size())
            return 2;
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) { return a[0] < b[0] || a[0] == b[0] && a[1] > b[1]; });
        int t = intervals.size();
        vector<int> todo(t, 2);
        int res = 0;
        while (--t >= 0)
        {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];
            for (int p = s; p < s + m; ++p)
            {
                for (int i = 0; i <= t; ++i)
                    if (todo[i] > 0 && p <= intervals[i][1])
                        todo[i]--;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

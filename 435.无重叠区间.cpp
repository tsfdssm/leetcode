/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) -> bool { return a[1] < b[1]; });
        int ed = INT_MIN;
        int res = 0;
        for (const auto &a : intervals)
        {
            if (a[0] >= ed)
            {
                ++res;
                ed = a[1];
            }
        }
        return n - res;
    }
};
// @lc code=end

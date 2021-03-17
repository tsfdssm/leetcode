/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        if (intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (res.empty() || res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

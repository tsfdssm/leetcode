/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < m && j < n)
        {
            if (hasCom(a[i], b[j]))
            {
                int st = max(a[i][0], b[j][0]);
                int ed = min(a[i][1], b[j][1]);
                res.push_back({st, ed});
            }
            if (a[i][1] < b[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return res;
    }

    bool inline hasCom(const vector<int> &a, const vector<int> &b)
    {
        return !(a[1] < b[0] || b[1] < a[0]);
    }
};
// @lc code=end

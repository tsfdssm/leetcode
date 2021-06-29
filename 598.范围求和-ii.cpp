/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        for (const auto &op : ops)
        {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                res[j][i] = grid[i][j];
            }
        return res;
    }
};
// @lc code=end

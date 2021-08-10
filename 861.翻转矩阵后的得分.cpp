/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = m * (1 << (n - 1));
        for (int i = 1; i < n; ++i)
        {
            int k = 0;
            for (int j = 0; j < m; ++j)
                if (!grid[j][i] ^ grid[j][0])
                    ++k;
            k = max(k, m - k);
            res += k * (1 << (n - i - 1));
        }
        return res;
    }
};
// @lc code=end

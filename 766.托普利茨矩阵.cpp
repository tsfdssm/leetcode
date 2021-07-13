/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (0 == i || 0 == j)
                    continue;
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        return true;
    }
};
// @lc code=end

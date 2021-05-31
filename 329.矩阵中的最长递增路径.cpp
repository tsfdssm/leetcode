/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> vis;
    int m;
    int n;
    int backtrack(int i, int j, int lastVal, vector<vector<int>> &matrix)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        if (matrix[i][j] <= lastVal)
            return 0;
        if (-1 != vis[i][j])
            return vis[i][j];
        vector<int> tmp(4, 0);
        tmp[0] = backtrack(i - 1, j, matrix[i][j], matrix);
        tmp[1] = backtrack(i + 1, j, matrix[i][j], matrix);
        tmp[2] = backtrack(i, j - 1, matrix[i][j], matrix);
        tmp[3] = backtrack(i, j + 1, matrix[i][j], matrix);
        vis[i][j] = 1 + *max_element(tmp.begin(), tmp.end());
        return vis[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        if (0 == m)
            return 0;
        n = matrix[0].size();
        vis.resize(m, vector<int>(n, -1));
        int maxN = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxN = max(maxN, backtrack(i, j, -1, matrix));
        return maxN;
    }
};
// @lc code=end

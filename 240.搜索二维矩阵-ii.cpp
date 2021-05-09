/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        if (0 == m)
            return false;
        int n = matrix[0].size();

        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] > target)
            {
                --i;
            }
            else if (matrix[i][j] < target)
            {
                ++j;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

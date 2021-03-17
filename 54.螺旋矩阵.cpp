/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> res;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if (top < bottom && left < right)
            {
                for (int i = right - 1; i > left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                for (int i = bottom; i > top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return res;
    }
};
// @lc code=end

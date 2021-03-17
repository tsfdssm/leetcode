/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (1 == matrix.size())
            return;
        int n = (int)matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; 2 * j < n - 1; j++)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
// @lc code=end

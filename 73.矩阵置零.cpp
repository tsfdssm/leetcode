/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <stdlib.h>
#include <string>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (0 == matrix.size())
            return;
        const int flag = rand();
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (0 == matrix[i][j])
                {
                    for (int t = 0; t < matrix.size(); t++)
                        if (0 != matrix[t][j])
                            matrix[t][j] = flag;
                    for (int k = 0; k < matrix[0].size(); k++)
                        if (0 != matrix[i][k])
                            matrix[i][k] = flag;
                }
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (flag == matrix[i][j])
                    matrix[i][j] = 0;
    }
};
// @lc code=end

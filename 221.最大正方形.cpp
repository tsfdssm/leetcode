/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (0 == m)
            return 0;
        int n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ('0' == matrix[i][j])
                    continue;
                int k = 1;
                bool flag = true;
                while (i + k < m && j + k < n)
                {
                    for (int tmp = 0; tmp <= k; ++tmp)
                    {
                        if (matrix[i + tmp][j + k] != '1' || matrix[i + k][j + tmp] != '1')
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                    ++k;
                }
                res = max(res, k);
            }
        }
        return res * res;
    }
};
// @lc code=end

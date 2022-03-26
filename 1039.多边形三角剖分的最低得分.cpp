/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        int d[n][n];
        memset(d, 0, sizeof(d));

        for (int j = 2; j < n; ++j)
        {
            for (int i = j - 2; i >= 0; --i)
            {
                for (int k = i + 1; k < j; ++k)
                {
                    if (d[i][j] != 0)
                    {
                        d[i][j] = min(d[i][j], values[i] * values[j] * values[k] + d[i][k] + d[k][j]);
                    }
                    else
                    {
                        d[i][j] = values[i] * values[j] * values[k] + d[i][k] + d[k][j];
                    }
                }
            }
        }

        return d[0][n - 1];
    }
};
// @lc code=end

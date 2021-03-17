/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = numRows;
        vector<vector<int>> res(n);
        for (int i = 1; i <= n; i++)
        {
            res[i - 1].resize(i, 1);
            for (int j = 1; j < i - 1; ++j)
            {
                res[i - 1][j] = res[i - 2][j - 1] + res[i - 2][j];
            }
        }
        return res;
    }
};
// @lc code=end

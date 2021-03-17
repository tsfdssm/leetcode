/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> &t = triangle;

        vector<int> res(n, 0);
        res[0] = t[0][0];
        for (int i = 1; i < n; ++i)
        {
            res[i] = res[i - 1] + t[i][i];
            for (int j = i - 1; j > 0; j--)
            {
                res[j] = min(res[j - 1], res[j]) + t[i][j];
            }
            res[0] += t[i][0];
        }
        return *min_element(res.begin(), res.end());
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        int index = 1;
        vector<vector<int>> res(n, vector<int>(n));
        while (l <= r && t <= b)
        {
            for (int i = l; i <= r; i++)
                res[t][i] = index++;
            for (int i = t + 1; i <= b; i++)
                res[i][r] = index++;
            if (l < r && t < b)
            {
                for (int i = r - 1; i >= l; i--)
                    res[b][i] = index++;
                for (int i = b - 1; i > t; i--)
                    res[i][l] = index++;
            }
            l++;
            r--;
            t++;
            b--;
        }
        return res;
    }
};
// @lc code=end

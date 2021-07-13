/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start
class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        if (mines.size() == n * n)
            return 0;
        if (mines.size() > n * n - 5)
            return 1;
        vector<vector<int>> all(n, vector<int>(n, 1));
        int up[n][n];
        int down[n][n];
        int left[n][n];
        int right[n][n];

        //memset(all, 1, sizeof(all));
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for (const auto &vec : mines)
            all[vec[0]][vec[1]] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (0 == i)
                    up[i][j] = all[i][j];
                else
                    up[i][j] = all[i][j] == 0 ? 0 : up[i - 1][j] + 1;
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j < n; ++j)
                if (n - 1 == i)
                    down[i][j] = all[i][j];
                else
                    down[i][j] = all[i][j] == 0 ? 0 : down[i + 1][j] + 1;
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                if (0 == j)
                    left[i][j] = all[i][j];
                else
                    left[i][j] = all[i][j] == 0 ? 0 : left[i][j - 1] + 1;
        for (int j = n - 1; j >= 0; --j)
            for (int i = 0; i < n; ++i)
                if (n - 1 == j)
                    right[i][j] = all[i][j];
                else
                    right[i][j] = all[i][j] == 0 ? 0 : right[i][j + 1] + 1;
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (all[i][j] == 1)
                {
                    int minn = min(up[i][j], down[i][j]);
                    minn = min(minn, min(left[i][j], right[i][j]));
                    res = max(res, minn);
                }
        return res;
    }
};
// @lc code=end

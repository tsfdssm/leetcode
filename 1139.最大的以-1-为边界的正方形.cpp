/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 *
 * https://leetcode.cn/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (48.68%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 22.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回
 * 0。
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：9
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[1,1,0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> up(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    up[i][j] = (i ? up[i - 1][j] : 0) + 1;
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    left[i][j] = (j ? left[i][j - 1] : 0) + 1;
            }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                int k = min(left[i][j], up[i][j]);
                for (int minn = k; minn >= 1; --minn)
                {
                    if ((left[i - minn + 1][j] >= minn) && (up[i][j - minn + 1] >= minn))
                        res = max(res, minn * minn);
                }
            }

        return res;
    }
};
// @lc code=end

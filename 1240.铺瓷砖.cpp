/*
 * @lc app=leetcode.cn id=1240 lang=cpp
 *
 * [1240] 铺瓷砖
 *
 * https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/description/
 *
 * algorithms
 * Hard (50.22%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 6.2K
 * Testcase Example:  '2\n3'
 *
 * 你是一位施工队的工长，根据设计师的要求准备为一套设计风格独特的房子进行室内装修。
 *
 * 房子的客厅大小为 n x m，为保持极简的风格，需要使用尽可能少的 正方形 瓷砖来铺盖地面。
 *
 * 假设正方形瓷砖的规格不限，边长都是整数。
 *
 * 请你帮设计师计算一下，最少需要用到多少块方形瓷砖？
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 2, m = 3
 * 输出：3
 * 解释：3 块地砖就可以铺满卧室。
 * ⁠    2 块 1x1 地砖
 * ⁠    1 块 2x2 地砖
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 5, m = 8
 * 输出：5
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：n = 11, m = 13
 * 输出：6
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 13
 * 1 <= m <= 13
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int tilingRectangle(const int n, const int m)
    {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int total = n * m;
        int res = total;

        function<void(int, int, int, int)> dfs = [&](int x, int y, int sum, int rest)
        {
            if ((sum + 1) >= res)
                return;
            int len = min(n - x, m - y);
            for (int k = len; k >= 1; --k)
            {
                // if (rest < (k * k))
                // continue;
                bool flag = true;
                // int flag = 0;
                for (int i = x; (i < x + k) && flag; ++i)
                    for (int j = y; (j < y + k) && flag; ++j)
                    {
                        if (1 == grid[i][j])
                        {
                            flag = false; // min(i - x, j - y);
                        }
                    }

                if (!flag)
                {
                    // k = flag;
                    continue;
                }
                for (int i = x; i < (x + k); ++i)
                    for (int j = y; j < (y + k); ++j)
                        grid[i][j] = 1;

                rest -= k * k;
                if (rest == 0)
                {
                    res = min(res, sum + 1);
                }
                else
                {
                    int nx = 0;
                    int ny = 0;
                    bool f = true;
                    for (int i = 0; (i < n) && f; ++i)
                        for (int j = 0; (j < m) && f; ++j)
                            if (0 == grid[i][j])
                            {
                                f = false;
                                nx = i;
                                ny = j;
                            }

                    dfs(nx, ny, sum + 1, rest);
                }
                rest += k * k;
                for (int i = x; i < (x + k); ++i)
                    for (int j = y; j < (y + k); ++j)
                        grid[i][j] = 0;
            }
        };
        dfs(0, 0, 0, total);
        return res;
    }
};
// @lc code=end

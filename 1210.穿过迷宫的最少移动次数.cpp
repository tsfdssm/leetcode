/*
 * @lc app=leetcode.cn id=1210 lang=cpp
 *
 * [1210] 穿过迷宫的最少移动次数
 *
 * https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations/description/
 *
 * algorithms
 * Hard (45.79%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 6.6K
 * Testcase Example:  '[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]\r'
 *
 * 你还记得那条风靡全球的贪吃蛇吗？
 *
 * 我们在一个 n*n 的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。蛇会从左上角（(0, 0) 和 (0,
 * 1)）开始移动。我们用 0 表示空单元格，用 1 表示障碍物。蛇需要移动到迷宫的右下角（(n-1, n-2) 和 (n-1, n-1)）。
 *
 * 每次移动，蛇可以这样走：
 *
 *
 * 如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。
 * 如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。
 * 如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（(r, c)、(r, c+1)）移动到 （(r, c)、(r+1,
 * c)）。
 *
 * 如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（(r, c)、(r+1, c)）移动到（(r, c)、(r,
 * c+1)）。
 *
 *
 *
 * 返回蛇抵达目的地所需的最少移动次数。
 *
 * 如果无法到达目的地，请返回 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[0,0,0,0,0,1],
 * ⁠              [1,1,0,0,1,0],
 * [0,0,0,0,1,1],
 * [0,0,1,0,1,0],
 * [0,1,1,0,0,0],
 * [0,1,1,0,0,0]]
 * 输出：11
 * 解释：
 * 一种可能的解决方案是 [右, 右, 顺时针旋转, 右, 下, 下, 下, 下, 逆时针旋转, 右, 下]。
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[0,0,1,1,1,1],
 * [0,0,0,0,1,1],
 * [1,1,0,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,0]]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 100
 * 0 <= grid[i][j] <= 1
 * 蛇保证从空单元格开始出发。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    using vi = vector<int>;
    using vii = vector<vi>;
    using viii = vector<vii>;
    int minimumMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        const int inf = 0x3f3f3f3f;

        auto inGrid = [&](int x, int y)
        {
            return 0 <= x && x < n && 0 <= y && y < n;
        };

        queue<tuple<int, int, int>> q;
        map<tuple<int, int, int>, int> st;
        q.push({0, 1, 0});
        int step = 0;
        while (!q.empty())
        {
            step++;
            int len = q.size();
            for (int l = 0; l < len; ++l)
            {
                auto cur = q.front();
                q.pop();
                int i = get<0>(cur);
                int j = get<1>(cur);
                int k = get<2>(cur);
                // k==0
                if (0 == k)
                {
                    if (!st.count({i, j + 1, 0}) && inGrid(i, j + 1) && (0 == grid[i][j + 1]))
                    {
                        q.push({i, j + 1, 0});
                        st[{i, j + 1, 0}] = step;
                    }
                    if (!st.count({i + 1, j, 0}) && inGrid(i + 1, j - 1) && inGrid(i + 1, j) && (0 == grid[i + 1][j - 1]) && (0 == grid[i + 1][j]))
                    {
                        q.push({i + 1, j, 0});
                        st[{i + 1, j, 0}] = step;
                    }
                    if (!st.count({i + 1, j - 1, 1}) && inGrid(i + 1, j - 1) && inGrid(i + 1, j) && (0 == grid[i + 1][j - 1]) && (0 == grid[i + 1][j]))
                    {
                        q.push({i + 1, j - 1, 1});
                        st[{i + 1, j - 1, 1}] = step;
                    }
                }

                // k==1;
                if (1 == k)
                {
                    if (!st.count({i + 1, j, 1}) && inGrid(i + 1, j) && (0 == grid[i + 1][j]))
                    {
                        q.push({i + 1, j, 1});
                        st[{i + 1, j, 1}] = step;
                    }
                    if (!st.count({i, j + 1, 1}) && inGrid(i - 1, j + 1) && inGrid(i, j + 1) && (0 == grid[i - 1][j + 1]) && (0 == grid[i][j + 1]))
                    {
                        q.push({i, j + 1, 1});
                        st[{i, j + 1, 1}] = step;
                    }
                    if (!st.count({i - 1, j + 1, 0}) && inGrid(i - 1, j + 1) && inGrid(i, j + 1) && (0 == grid[i - 1][j + 1]) && (0 == grid[i][j + 1]))
                    {
                        q.push({i - 1, j + 1, 0});
                        st[{i - 1, j + 1, 0}] = step;
                    }
                }
                if (st.count({n - 1, n - 1, 0}))
                    return st[{n - 1, n - 1, 0}];
            }
        }
        return -1;
    }
};
// @lc code=end

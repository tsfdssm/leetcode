/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode.cn/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (47.01%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 96.8K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 n x n 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地。
 *
 * 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
 *
 * 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释：
 * 海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：grid = [[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释：
 * 海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] 不是 0 就是 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> dis(n, vector<int>(n, inf));
        vector<vector<int>> vis(n, vector<int>(n, -1));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        auto inGrid = [&](int x, int y)
        {
            return 0 <= x && x < n && 0 <= y && y < n;
        };
        auto bfs = [&](int x, int y)
        {
            queue<pair<int, int>> q;
            q.push({x, y});
            int d = 0;
            int id = x * n + y;
            while (!q.empty())
            {
                d++;
                int len = q.size();
                for (int i = 0; i < len; ++i)
                {
                    auto [cx, cy] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (!inGrid(nx, ny))
                            continue;
                        if (vis[nx][ny] == id)
                            continue;
                        vis[nx][ny] = id;
                        if (1 == grid[nx][ny])
                            continue;

                        if (dis[nx][ny] <= d)
                            continue;
                        dis[nx][ny] = d;
                        q.push({nx, ny});
                    }
                }
            }
        };

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (1 == grid[i][j])
                    bfs(i, j);

        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (0 == grid[i][j])
                {
                    res = max(res, dis[i][j]);
                }
        if ((res == inf) || (res == 0))
            res = -1;
        return res;
    }
};
// @lc code=end

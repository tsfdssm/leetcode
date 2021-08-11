/*
 * @lc app=leetcode.cn id=885 lang=cpp
 *
 * [885] 螺旋矩阵 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {

        auto inGrid = [&](int x, int y) -> bool {
            return 0 <= x && x < rows && 0 <= y && y < cols;
        };
        int x = rStart;
        int y = cStart;
        int maxn = rows * cols;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int d = 0;
        int len = 0;
        vector<vector<int>> res;
        res.push_back({x, y});
        while (res.size() < maxn)
        {
            if (0 == d || 2 == d)
                ++len;
            for (int i = 0; i < len; ++i)
            {
                x += dx[d];
                y += dy[d];
                if (inGrid(x, y))
                    res.push_back({x, y});
            }
            d++;
            d %= 4;
        }
        return res;
    }
};
// @lc code=end

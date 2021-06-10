/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();
        //swap(m, n);
        if (m < 3 || n < 3)
            return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (0 == i || 0 == j || (m - 1) == i || (n - 1) == j)
                {
                    que.push({heightMap[i][j], i * n + j});
                    heightMap[i][j] = -1;
                }

        int res = 0;
        int maxH = 0;

        int x[4] = {0, 0, 1, -1};
        int y[4] = {1, -1, 0, 0};
        while (!que.empty())
        {
            const auto &cur = que.top();
            int h = cur.first;
            int i = cur.second / n;
            int j = cur.second % n;
            que.pop();
            if (h > maxH)
                maxH = h;
            for (int k = 0; k < 4; ++k)
            {

                int tmpi = i + x[k];
                int tmpj = j + y[k];
                if (tmpi > 0 && tmpj > 0 && tmpi < m && tmpj < n && heightMap[tmpi][tmpj] != -1)
                {
                    que.push({heightMap[tmpi][tmpj], tmpi * n + tmpj});
                    if (maxH > heightMap[tmpi][tmpj])
                        res += maxH - heightMap[tmpi][tmpj];
                    heightMap[tmpi][tmpj] = -1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

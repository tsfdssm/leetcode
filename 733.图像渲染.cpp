/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        int m = image.size();
        int n = image[0].size();
        int dir_x[4] = {0, 0, 1, -1};
        int dir_y[4] = {1, -1, 0, 0};

        vector<int> vis(m * n, false);
        queue<int> q;
        q.push(sr * n + sc);
        vis[sr * n + sc] = true;
        int row = image[sr][sc];
        while (!q.empty())
        {
            auto cur = q.front();
            image[cur / n][cur % n] = newColor;
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int now = cur + dir_x[k] * n + dir_y[k];
                if (k == 0 && (now % n == 0))
                    continue;
                if (k == 1 && (now % n == n - 1))
                    continue;
                if (now < 0 || now >= (m * n) || vis[now])
                    continue;
                if (image[now / n][now % n] == row)
                {
                    vis[now] = true;
                    q.push(now);
                }
            }
        }
        return image;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int dir_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dir_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int sum = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; ++k)
                {
                    int tmpi = i + dir_x[k];
                    int tmpj = j + dir_y[k];
                    if (tmpi < 0 || tmpi >= m || tmpj < 0 || tmpj >= n)
                        continue;
                    sum += img[tmpi][tmpj];
                    ++cnt;
                }
                res[i][j] = sum / cnt;
            }
        return res;
    }
};
// @lc code=end

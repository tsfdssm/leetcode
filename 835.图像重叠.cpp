/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        int res = 0;
        for (int i = 1 - n; i < n; ++i)
            for (int j = 1 - n; j < n; ++j)
            {
                int cnt = 0;
                for (int tmpi = 0; tmpi < n; ++tmpi)
                    if ((i + tmpi < 0) || (i + tmpi >= n))
                        continue;
                    else
                        for (int tmpj = 0; tmpj < n; ++tmpj)
                        {
                            if ((j + tmpj < 0) || (j + tmpj >= n))
                                continue;
                            if (1 == img1[tmpi][tmpj] && 1 == img2[i + tmpi][j + tmpj])
                                cnt++;
                        }
                res = max(cnt, res);
            }

        return res;
    }
};
// @lc code=end

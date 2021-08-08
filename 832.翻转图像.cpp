/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (auto &row : image)
            reverse(row.begin(), row.end());
        int n = image.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                image[i][j] ^= 1;
        return image;
    }
};
// @lc code=end

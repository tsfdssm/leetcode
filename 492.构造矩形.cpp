/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int l = 0;
        int w = 0;
        w = sqrt(area);
        while (area % w != 0)
            --w;
        l = area / w;
        return {l, w};
    }
};
// @lc code=end

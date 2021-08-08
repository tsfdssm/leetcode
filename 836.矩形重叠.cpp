/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return isOver(rec1[1], rec1[3], rec2[1], rec2[3]) && isOver(rec1[0], rec1[2], rec2[0], rec2[2]);
    }

    inline bool isOver(int a, int b, int c, int d)
    {
        return c < b && d > a;
    }
};
// @lc code=end

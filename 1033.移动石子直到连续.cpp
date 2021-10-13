/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */

// @lc code=start
class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        // 排序
        if (a > b)
        {
            swap(a, b);
        }
        if (a > c)
        {
            swap(a, c);
        }
        if (b > c)
        {
            swap(b, c);
        }

        // 相邻，无法启动
        if (a == b - 1 && b == c - 1)
        {
            return {0, 0};
        }

        if (b - a == 1 || c - b == 1 || b - a == 2 || c - b == 2)
        {
            return {1, c - a - 2};
        }

        return {2, c - a - 2};
    }
};
// @lc code=end

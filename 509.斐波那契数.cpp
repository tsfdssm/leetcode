/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (0 == n)
            return 0;
        if (1 == n)
            return 1;
        int i = 0;
        int a = 0;
        int b = 1;
        while (i < n - 1)
        {
            int tmp = a;
            a = b;
            b = tmp + a;
            ++i;
        }
        return b;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution
{
public:
    int clumsy(int n)
    {
        int cnt = n / 4;
        int left = n % 4;
        int res = 0;
        if (cnt >= 1)
        {
            res += n * (n - 1) / (n - 2) + n - 3;
            n -= 4;
            while (n >= 4)
            {
                res += -n * (n - 1) / (n - 2) + n - 3;
                n -= 4;
            }
            if (3 == n)
            {
                res += -6;
            }
            else if (2 == n)
            {
                res += -2;
            }
            else if (1 == n)
            {
                res += -1;
            }
            else
            {
            }
        }
        else
        {
            if (3 == n)
            {
                res += 6;
            }
            else if (2 == n)
            {
                res += 2;
            }
            else if (1 == n)
            {
                res += 1;
            }
            else
            {
            }
        }
        return res;
    }
};
// @lc code=end

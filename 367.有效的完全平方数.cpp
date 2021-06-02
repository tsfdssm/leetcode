/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (2 > num)
            return true;

        long long x = num / 2;
        while (x * x > num)
        {
            x = (x + num / x) / 2;
        }
        return x * x == num;
        // if (0 == num || 1 == num)
        //     return true;
        // int l = 0, r = num;
        // long long mid = 0;
        // while (l <= r)
        // {
        //     mid = l + ((r - l) >> 1);
        //     long long tmp = mid * mid;
        //     if (tmp == (long long)num)
        //     {
        //         return true;
        //     }
        //     else if (tmp > (long long)num)
        //     {
        //         r = mid - 1;
        //     }
        //     else
        //     {
        //         l = mid + 1;
        //     }
        // }
        // return false;
    }
};
// @lc code=end

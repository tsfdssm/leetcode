/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution
{
public:
    inline bool check(int x)
    {
        bool same = true;
        while (x > 0)
        {
            int digit = x % 10;
            x /= 10;
            if ((digit == 0) || (digit == 1) || (digit == 8))
            {
            }
            else if ((digit == 2) || (digit == 5) || (digit == 6) || (digit == 9))
            {
                same = false;
            }
            else
                return false;
        }
        return !same;
    }

    int rotatedDigits(int n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (check(i))
                ++cnt;
        return cnt;
    }
};
// @lc code=end

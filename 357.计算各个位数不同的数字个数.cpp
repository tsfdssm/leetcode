/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        if (1 == n)
            return 10;
        if (n > 10)
            return 0;

        int last = 10;
        int tmp = 9;
        --n;
        for (int i = 0; i < n; ++i)
        {
            tmp *= (9 - i);
            last += tmp;
        }
        return last;
    }
};
// @lc code=end

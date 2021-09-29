/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */

// @lc code=start
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int cnt = 1;
        int num = 1;
        while (1)
        {
            if (num % k == 0)
                return cnt;
            ++cnt;
            num = (num % k) * 10 + 1;
        }
        return cnt;
    }
};
// @lc code=end

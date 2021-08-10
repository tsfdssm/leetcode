/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution
{
public:
    int binaryGap(int n)
    {
        int res = 0;
        int k = 31;
        while (k >= 0 && !(n & (1 << k)))
            --k;
        while (k > 0)
        {
            int prev = k;
            --k;
            while (k >= 0 && !(n & (1 << k)))
                --k;
            if (k >= 0)
                res = max(res, prev - k);
        }
        return res;
    }
};
// @lc code=end

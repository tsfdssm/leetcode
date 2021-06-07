/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution
{
public:
    int integerReplacement(int t)
    {
        int cnt = 0;
        long long x = t;
        while (x != 1)
        {
            if (x & 1)
            {
                x += (!(x & 2) || (3 == x)) ? -1 : 1;
            }
            else
            {
                x >>= 1;
            }
            cnt++;
        }
        return cnt;
        // int k = 31;
        // while ((x & (1 << k)) == 0)
        //     --k;
        // int res = k;
        // for (int i = 0; i < k; ++i)
        // {
        //     if (x & (1 << i))
        //     {
        //         ++res;
        //     }
        // }
        // return res;
    }
};
// @lc code=end

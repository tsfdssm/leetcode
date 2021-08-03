/*
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */

// @lc code=start
class Solution
{
public:
    int racecar(int target)
    {
        const int inf = 0x3f3f3f3f;
        vector<int> dp(target + 2, inf);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 4;
        for (int t = 3; t <= target; ++t)
        {
            int k = 31;
            while (!(t & (1 << k)))
                --k;
            ++k;
            if (t == (1 << k) - 1)
            {
                dp[t] = k;
                continue;
            }
            for (int j = 0; j < k - 1; ++j)
                dp[t] = min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            if ((1 << k) - 1 - t < t)
                dp[t] = min(dp[t], dp[(1 << k) - 1 - t] + k + 1);
        }
        return dp[target];
        // int k = 31;
        // int res = 0;
        // int last = 0;
        // int cnt = 0;
        // while (k >= 0)
        // {
        //     if (target & (1 << k))
        //     {
        //         if (0 == last)
        //         {
        //             res += k + 1;
        //             last = 1;
        //             cnt++;
        //         }
        //         else
        //         {
        //         }
        //     }
        //     else
        //     {
        //         if (1 == last)
        //         {
        //             res += k + 1;
        //             last = 0;
        //             cnt++;
        //         }
        //         else
        //         {
        //         }
        //     }
        //     --k;
        // }
        // res += cnt - 1;
        // return res;
    }
};
// @lc code=end

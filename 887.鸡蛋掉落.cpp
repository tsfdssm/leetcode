/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int j = 1; j <= k; ++j)
            dp[1][j] = 1;
        for (int f = 1; f <= n; ++f)
            dp[f][1] = f;
        for (int f = 1; f <= n; ++f) ///f次操作，j个蛋，能探索的层数
            for (int j = 1; j <= k; ++j)
            {
                dp[f][j] = dp[f - 1][j] + dp[f - 1][j - 1] + 1;
                if (dp[f][j] >= n)
                    return f;
            }
        return n;

        // const int inf = 0x3f3f3f3f;
        // vector<vector<int>> dp(k + 1, vector<int>(n + 1, inf));
        // for (int i = 0; i <= k; ++i)
        // {
        //     dp[i][0] = 0;
        //     dp[i][1] = 1;
        // }
        // for (int j = 1; j <= n; ++j)
        // {
        //     dp[0][j] = 0;
        //     dp[1][j] = j;
        // }
        // for (int i = 2; i <= k; ++i)
        //     for (int j = 2; j <= n; ++j)
        //     {
        //         int l = 1, r = j + 1;
        //         while (l < r)
        //         {
        //             int mid = l + (r - l) / 2;
        //             if (dp[i - 1][mid - 1] >= dp[i][j - mid])
        //             {
        //                 r = mid;
        //             }
        //             else
        //             {
        //                 l = mid + 1;
        //             }
        //         }
        //         dp[i][j] = min(max(dp[i - 1][l - 2], dp[i][j - l + 1]), max(dp[i - 1][l - 1], dp[i][j - l])) + 1;
        //         // for (int t = 1; t <= j; ++t)
        //         // {
        //         //     int cur = 0;
        //         //     cur = max(dp[i - 1][t - 1], dp[i][j - t]);
        //         //     dp[i][j] = min(dp[i][j], cur + 1);
        //         // }
        //         // if (j % 2 == 0) //长度为奇数
        //         //     dp[i][j] = max(dp[i - 1][(j + 1) / 2 - 1], dp[i][(j + 1) / 2]) + 1;
        //         // else
        //         //     dp[i][j] = max(dp[i - 1][(j + 1) / 2 - 1], dp[i][(j + 1) / 2 - 1]) + 1;
        //     }
        // return dp[k][n];
    }
};
// @lc code=end

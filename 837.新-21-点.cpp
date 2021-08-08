/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新21点
 */

// @lc code=start
class Solution
{
public:
    double new21Game(int n, int k, int w)
    {
        if (n >= k + w - 1)
            return 1.0;
        vector<double> dp(k + w);
        for (int i = k; i <= n; ++i)
            dp[i] = 1.0;
        double sum = n - k + 1;
        for (int i = k - 1; i >= 0; --i)
        {
            dp[i] = sum / w;
            sum += dp[i] - dp[i + w];
        }
        return dp[0];

        // double res = 0.0;
        // double multi = 1.0 / w;
        // function<void(int, int, double)> dfs = [&](int idx, int cur, double prob) {
        //     if (cur > n)
        //         return;
        //     if (cur >= k)
        //     {
        //         res += prob;
        //         return;
        //     }
        //     for (int i = idx; i <= w; ++i)
        //     {
        //         if (0 == i)
        //             continue;
        //         dfs(i, cur + i, prob * multi);
        //     }
        // };
        // dfs(0, 0, 1.0);
        // return res;

        // if (n >= k + w)
        //     return 1.0;
        // if (k > 8000)
        // {
        //     double res = 1.0;
        //     int cnt = 0;
        //     for (int i = 0; i <= (n - k); ++i)
        //         cnt += w - i;
        //     res *= cnt;
        //     res /= (w + 1) * w / 2;
        //     return res;
        // }
        // vector<double> dp(n + 1, 0.0);
        // dp[0] = 1.0;
        // for (int i = 0; i < k; ++i)
        // {
        //     for (int j = i + 1; j <= n && j <= i + w; ++j)
        //     {
        //         dp[j] += dp[i] / w;
        //     }
        // }
        // return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};
// @lc code=end

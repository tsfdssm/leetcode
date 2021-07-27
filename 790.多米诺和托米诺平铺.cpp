/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        const int mod = 1e9 + 7;
        if (n < 3)
            return n;
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = ((long long)2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string &s)
    {

        int n = s.size();
        const int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        if ('0' == s[0])
            return 0;
        else if ('*' == s[0])
        {
            dp[1] = 9;
        }
        else
        {
            dp[1] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            char c = s[i - 1];
            char l = s[i - 2];
            if ('*' == c)
            {
                dp[i] = dp[i - 1] * 9;
                if ('1' == l)
                    dp[i] += dp[i - 2] * 9;
                else if ('2' == l)
                    dp[i] += dp[i - 2] * 6;
                else if ('*' == l)
                    dp[i] += dp[i - 2] * 15;
                else
                {
                }
            }
            else if ('0' == c)
            {
                if ('*' == l)
                    dp[i] = dp[i - 2] * 2;
                else if ('1' == l || '2' == l)
                    dp[i] = dp[i - 2];
                else
                    return 0;
            }
            else
            {
                dp[i] = dp[i - 1];
                if ('0' <= c && c <= '6')
                {
                    if ('1' == l || '2' == l)
                        dp[i] += dp[i - 2];
                    else if ('*' == l)
                        dp[i] += dp[i - 2] * 2;
                    else
                    {
                    }
                }
                else
                {
                    if ('1' == l || '*' == l)
                        dp[i] += dp[i - 2];
                    else
                    {
                    }
                }
            }
            dp[i] %= mod;
        }
        return (int)dp[n];
    }
};
// @lc code=end

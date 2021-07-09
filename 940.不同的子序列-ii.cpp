/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution
{
public:
    int distinctSubseqII(const string &s)
    {
        int n = s.size();
        const int mod = 1e9 + 7;
        vector<int> dp(26, 0);
        int sum = 0;
        int add = 0;
        for (char c : s)
        {
            add = (sum - dp[c - 'a'] + 1) % mod;
            sum = (sum + add) % mod;
            dp[c - 'a'] = (dp[c - 'a'] + add) % mod;
        }
        return (sum + mod) % mod;
    }
};
// @lc code=end

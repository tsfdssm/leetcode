/*
 * @lc app=leetcode.cn id=1915 lang=cpp
 *
 * [1915] 最美子字符串的数目
 */

// @lc code=start
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        int n = word.size();
        int m = 10;
        vector<int> dp(1 << m);
        int state = 1 << (word[0] - 'a');
        dp[state] = 1;
        dp[0] = 1;
        long long res = 1;
        for (int i = 1; i < n; ++i)
        {
            int j = word[i] - 'a';
            state ^= 1 << j;
            res += dp[state];
            for (int k = 0; k < 10; ++k)
                res += dp[state ^ (1 << k)];
            dp[state]++;
        }
        return res;
    }
};
// @lc code=end

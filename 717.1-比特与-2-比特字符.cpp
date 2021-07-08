/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        vector<bool> dp(n, true);
        for (int i = 0; i < n; ++i)
        {
            if (false == dp[i])
                continue;
            if (bits[i] == 1)
            {
                dp[i] = false;
                if (i < n - 1)
                    dp[i + 1] = false;
            }
            else
            {
                dp[i] = true;
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

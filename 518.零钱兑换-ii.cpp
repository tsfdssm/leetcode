/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution
{
public:
    // int target = 0;
    // int n = 0;
    // int res = 0;
    // void dfs(vector<int> &coins, int i, int cur)
    // {
    //     if (i == n)
    //         return;
    //     if (cur > target)
    //         return;
    //     if (cur == target)
    //     {
    //         res++;
    //         return;
    //     }
    //     dfs(coins, i, cur + coins[i]);
    //     dfs(coins, i + 1, cur);
    // }
    // int change(int amount, vector<int> &coins)
    // {
    //     target = amount;
    //     n = coins.size();
    //     sort(coins.begin(), coins.end());
    //     dfs(coins, 0, 0);
    //     return res;
    // }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

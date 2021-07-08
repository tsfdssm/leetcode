/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int zero = 0;
        int one = -prices[0];
        int n = prices.size();
        for (int i = 1; i < n; ++i)
        {
            //int t_zero = zero;
            // zero = max(zero, one + prices[i] - fee);
            // one = max(one, zero - prices[i]);
            tie(zero, one) = make_pair(max(zero, one + prices[i] - fee), max(one, zero - prices[i]));
        }
        return zero;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        for (int i = 1; i < n; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
        }
        return sell1;
        // if (prices.size() <= 1)
        //     return 0;
        // int min = INT32_MAX, max = 0;
        // for (int i = 0; i < prices.size(); ++i)
        // {
        //     if (min == INT32_MAX || prices[i] < prices[min])
        //         min = i;
        //     else
        //     {
        //         max = max > (prices[i] - prices[min]) ? max : (prices[i] - prices[min]);
        //     }
        // }
        // return max;
    }
};
// @lc code=end

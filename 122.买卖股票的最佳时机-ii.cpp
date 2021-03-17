/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        for (int i = 0; i < n; ++i)
        {
            buy1 = max(buy1, sell1 - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
        }
        return sell1;

        // int res = 0;
        // stack<int> st;
        // //st.push(0);
        // for (int i = 0; i < prices.size(); ++i)
        // {
        //     if (st.empty())
        //     {
        //         st.push(i);
        //     }
        //     else if (prices[i] > prices[st.top()])
        //     {
        //         res += prices[i] - prices[st.top()];
        //         st.push(i);
        //     }
        //     else
        //     {
        //         while (!st.empty() && prices[i] < prices[st.top()])
        //         {
        //             st.pop();
        //         }
        //         st.push(i);
        //     }
        // }
        // return res;

        // int res = 0;
        // for (int i = 1; i < prices.size(); ++i)
        // {
        //     res += max(0, prices[i] - prices[i - 1]);
        // }
        // return res;
    }
};
// @lc code=end

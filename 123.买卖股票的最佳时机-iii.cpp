/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
        // int res = 0;
        // vector<int> res_vec;
        // stack<int> st;
        // int min = 0;
        // for (int i = 0; i < prices.size(); ++i)
        // {
        //     if (st.empty())
        //     {
        //         st.push(i);
        //         min = prices[i];
        //     }
        //     else if (prices[i] > prices[st.top()])
        //     {
        //         res += prices[i] - prices[st.top()];
        //         st.push(i);
        //     }
        //     else if (min > prices[i])
        //     {
        //         min = prices[i];
        //         res_vec.push_back(res);
        //         res = 0;
        //         while (!st.empty() && prices[i] < prices[st.top()])
        //         {
        //             st.pop();
        //         }
        //         st.push(i);
        //     }
        //     else
        //     {
        //     }
        // }
        // if (!st.empty())
        //     res_vec.push_back(prices[st.top()] - min);
        // if (res_vec.empty())
        //     return 0;
        // else if (1 == res_vec.size())
        //     return res_vec[0];
        // else if (2 == res)
        //     return res_vec[0] + res_vec[1];

        // sort(res_vec.begin(), res_vec.end());
        // return res_vec[res_vec.size() - 1] + res_vec[res_vec.size() - 2];
    }
};
// @lc code=end

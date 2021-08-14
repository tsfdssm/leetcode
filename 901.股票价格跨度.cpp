/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner
{
public:
    vector<int> vec;
    stack<int> stk;
    int idx = -1;
    StockSpanner()
    {
    }

    int next(int price)
    {
        vec.emplace_back(price);
        ++idx;
        while (!stk.empty() && vec[stk.top()] <= price)
            stk.pop();
        if (stk.empty())
        {
            stk.push(idx);
            return idx + 1;
        }
        else
        {
            int res = idx - stk.top();
            stk.push(idx);
            return res;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            int num = temperatures[i];
            if (stk.empty() || temperatures[stk.top()] >= num)
            {
                stk.push(i);
            }
            else
            {
                while (!stk.empty() && temperatures[stk.top()] < num)
                {
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        while (!stk.empty())
        {
            res[stk.top()] = 0;
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

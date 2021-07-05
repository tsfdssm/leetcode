/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> stk;
        for (auto &s : ops)
        {
            if (s == "+")
            {
                int t = stk.top();
                stk.pop();
                int tmp = t + stk.top();
                stk.push(t);
                stk.push(tmp);
            }
            else if (s == "D")
            {
                stk.push(2 * stk.top());
            }
            else if (s == "C")
            {
                stk.pop();
            }
            else
            {
                stk.push(stoi(s));
            }
        }

        int res = 0;
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

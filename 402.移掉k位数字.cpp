/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (k >= n)
            return "0";
        int remain = n - k;
        string stk;
        for (auto c : num)
        {
            while (k > 0 && !stk.empty() && stk.back() > c)
            {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        int st = 0;
        stk = stk.substr(0, remain);
        while (st < n - 1 && stk[st] == '0')
            ++st;
        if (st == stk.size())
            return "0";
        return stk.substr(st);
    }
};
// @lc code=end

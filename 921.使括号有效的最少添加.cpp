/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if ('(' == c)
            {
                stk.push('(');
            }
            else
            {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(')');
            }
        }
        return stk.size();
    }
};
// @lc code=end

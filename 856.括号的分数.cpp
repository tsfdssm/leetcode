/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> stk;
        stk.push(0);
        for (char c : s)
        {
            if ('(' == c)
            {
                stk.push(0);
            }
            else
            {
                int s1 = stk.top();
                stk.pop();
                int s2 = stk.top();
                stk.pop();
                stk.push(max(1, 2 * s1) + s2);
            }
        }
        return stk.top();
    }
};
// @lc code=end

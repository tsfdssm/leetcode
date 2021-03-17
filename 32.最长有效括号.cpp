/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int max = 0;
        stack<int> stk;
        stk.push(-1);
        int tmp = 0;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (!stk.empty())
                {
                    tmp = i - stk.top();
                    max = max > tmp ? max : tmp;
                }
                else
                {
                    stk.push(i);
                }
            }
        }
        return max;
    }
};
// @lc code=end

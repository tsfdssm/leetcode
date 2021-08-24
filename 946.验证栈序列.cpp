/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int n = pushed.size();
        int l = 0, r = 0;
        stack<int> stk;
        for (; l < n; ++l)
        {
            stk.push(pushed[l]);
            while (!stk.empty() && popped[r] == stk.top())
            {
                stk.pop();
                ++r;
            }
        }
        return r == n;
    }
};
// @lc code=end

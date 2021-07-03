/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool one = false;
        stack<int> stk;
        for (int num : nums)
        {
            if (stk.empty() || stk.top() <= num)
            {
                stk.push(num);
                continue;
            }
            if (!one)
                one = true;
            else
                return false;
            int pre = stk.top();
            stk.pop();
            if (stk.empty() || stk.top() <= num)
                stk.push(num);
            else
                stk.push(pre);
        }
        return true;
    }
};
// @lc code=end

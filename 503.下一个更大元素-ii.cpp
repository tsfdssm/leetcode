/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i])
            {
                res[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i])
            {
                res[stk.top()] = nums[i];
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end

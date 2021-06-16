/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int n = nums.size();
        int k = INT_MIN;
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i)
        {
            int num = nums[i];
            if (num < k)
            {
                return true;
            }
            while (!stk.empty() && stk.top() < num)
            {
                k = max(k, stk.top());
                stk.pop();
            }
            stk.push(num);
        }
        return false;
    }
};
// @lc code=end

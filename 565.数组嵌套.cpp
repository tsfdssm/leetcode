/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        vector<int> vis(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {

            if (vis[i] > 0)
                continue;
            int j = nums[i];
            while (vis[j] == 0)
            {
                stk.push(j);
                vis[j] = 1;
                j = nums[j];
            }
            res = max(res, (int)stk.size());
            while (!stk.empty())
                stk.pop();
        }
        return res;
    }
};
// @lc code=end

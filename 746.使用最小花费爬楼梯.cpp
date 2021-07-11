/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ppre = cost[0];
        int pre = cost[1];
        for (int i = 2; i < n; ++i)
        {
            tie(ppre, pre) = make_pair(pre, min(pre, ppre) + cost[i]);
        }
        return min(pre, ppre);
    }
};
// @lc code=end

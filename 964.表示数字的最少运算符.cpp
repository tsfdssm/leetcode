/*
 * @lc app=leetcode.cn id=964 lang=cpp
 *
 * [964] 表示数字的最少运算符
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> mp;
    int dfs(int x, int target)
    {
        if (mp.count(target))
            return mp[target];
        if (x == target)
            return 0;
        else if (x > target)
        {
            //mp[target] = min(2 * target - 1, 2 * (x - target));
            return min(2 * target - 1, 2 * (x - target));
            //return mp[target];
        }
        else
        {
            int p = 0;
            long xp = x;
            while (xp < target)
            {
                xp *= x;
                ++p;
            }
            if (xp - target >= target)
            {
                return p - 1 + 1 + dfs(x, target - xp / x);
            }
            else
            {
                mp[target] = min(p - 1 + dfs(x, target - xp / x), p + dfs(x, xp - target)) + 1;
                return mp[target];
            }
        }
    }
    int leastOpsExpressTarget(int x, int target)
    {
        return dfs(x, target);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        long long n = timeSeries.size();
        long long res = n * duration;
        int last = -1;
        for (const int num : timeSeries)
        {
            if (num < last)
            {
                res -= last - num;
            }
            last = num + duration;
        }
        return res;
    }
};
// @lc code=end

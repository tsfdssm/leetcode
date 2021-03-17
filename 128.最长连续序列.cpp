/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (const auto &num : nums)
            set.insert(num);
        int res = 0;
        for (const auto &num : set)
        {
            if (0 == set.count(num - 1))
            {
                int curNum = num;
                int cur = 1;
                while (1 == set.count(++curNum))
                {
                    cur++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
// @lc code=end

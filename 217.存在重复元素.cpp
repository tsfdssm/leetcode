/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> res;
        for (const auto &num : nums)
        {
            if (1 == res.count(num))
                return true;
            res.insert(num);
        }
        return false;
    }
};
// @lc code=end

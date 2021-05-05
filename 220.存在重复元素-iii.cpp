/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        set<int> res;
        for (int i = 0; i < n; ++i)
        {
            auto iter = res.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != res.end() && *iter <= min(nums[i], INT_MAX - t) + t)
                return true;
            res.insert(nums[i]);
            if (i >= k)
                res.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end

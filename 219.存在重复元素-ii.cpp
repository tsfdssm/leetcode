/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = nums[i];
            if (0 == res.count(tmp) || (i - res[tmp] > k))
                res[tmp] = i;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end

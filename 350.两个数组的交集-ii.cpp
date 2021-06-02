/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> mp;
        vector<int> res;
        for (int num : nums2)
            mp[num]++;
        for (int num : nums1)
        {
            if (mp.count(num) && mp[num] > 0)
            {
                res.push_back(num);
                mp[num]--;
            }
        }
        return res;
    }
};
// @lc code=end

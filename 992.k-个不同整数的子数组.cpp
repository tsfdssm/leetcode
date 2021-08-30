/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int res = 0;
        unordered_map<int, int> mp;
        for (; r < n; ++r)
        {
            mp[nums[r]]++;
            while (mp.size() > k)
            {
                int last = nums[l++];
                mp[last]--;
                if (0 == mp[last])
                    mp.erase(last);
            }
            res += r - l;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
// @lc code=end

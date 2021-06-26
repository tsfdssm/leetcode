/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        int res = 0;
        for (int num : nums)
        {
            pre += num;
            if (mp.count(pre - k))
                res += mp[pre - k];
            mp[pre]++;
        }
        return res;
        // int n = nums.size();
        // vector<int> psum(nums);
        // for (int i = 1; i < n; ++i)
        //     psum[i] += psum[i - 1];
        // int res = 0;
        // for (int i = 0; i < n; ++i)
        //     for (int j = i; j < n; ++j)
        //         if ((0 == i && psum[j] == k) || (0 != i && psum[j] - psum[i - 1] == k))
        //             ++res;
        // return res;
    }
};
// @lc code=end

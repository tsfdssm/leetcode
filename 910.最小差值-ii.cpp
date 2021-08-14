/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; ++i)
        {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            res = min(res, high - low);
        }
        return res;
        // int r = *max_element(nums.begin(), nums.end());
        // int l = *min_element(nums.begin(), nums.end());
        // if (r - l >= 4 * k)
        //     return r - l - 2 * k;
        // if (r - l <= k)
        //     return r - l;
        // // k < r - l < 4 * k;
        // l += k;
        // r -= k;
        // if (l > r)
        //     swap(l, r);
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n; ++i)
        // {
        //     int num = nums[i];
        //     if ((l <= (num + k) && (num + k) <= r) || (l <= (num - k) && (num - k) <= r))
        //         continue;
        //     if (2 * num > r + l)
        //     {
        //         l = num - k;
        //     }
        //     else
        //     {
        //         r = num + k;
        //     }
        // }
        // return r - l;
    }
};
// @lc code=end

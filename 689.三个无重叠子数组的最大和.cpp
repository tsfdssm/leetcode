/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sum(n - k + 1, 0);
        int pre = accumulate(nums.begin(), nums.begin() + k, 0);
        sum[0] = pre;
        for (int i = k; i < n; ++i)
        {
            pre -= nums[i - k];
            pre += nums[i];
            sum[i + 1 - k] = pre;
        }
        int best = 0;
        int s = n - k + 1;
        vector<int> left(s, 0);
        for (int i = 0; i < s; ++i)
        {
            if (sum[i] > sum[best])
                best = i;
            left[i] = best;
        }
        best = s - 1;
        vector<int> right(s, 0);
        for (int i = s - 1; i >= 0; --i)
        {
            if (sum[i] >= sum[best])
                best = i;
            right[i] = best;
        }
        vector<int> res(3, -1);
        int maxn = 0;
        for (int j = k; j < s - k; ++j)
        {
            int tmp = sum[left[j - k]] + sum[j] + sum[right[j + k]];
            if (maxn < tmp)
            {
                res = {left[j - k], j, right[j + k]};
                maxn = tmp;
            }
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = accumulate(nums.begin(), nums.end(), 0);
        int cnt = 0;
        int minn = 1000;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= 0)
                ++cnt;
            minn = min(minn, abs(nums[i]));
        }

        if (k <= cnt)
        {
            int sum = -accumulate(nums.begin(), nums.begin() + k, 0);
            res += 2 * sum;
        }
        else
        {
            int sum = -accumulate(nums.begin(), nums.begin() + cnt, 0);
            res += 2 * sum;
            k -= cnt;
            k %= 2;
            if (k > 0)
                res -= 2 * minn;
        }
        return res;
    }
};
// @lc code=end

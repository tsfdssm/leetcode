/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> diff(n + k, 0);
        int cur = 0;
        int cnt = 0;
        int i = 0;
        for (; i <= n - k; ++i)
        {

            cur += diff[i];
            if ((cur + nums[i]) % 2 == 0)
            {
                cur++;
                cnt++;
                diff[i + k]--;
            }
        }
        for (; i < n; ++i)
        {
            cur += diff[i];
            if ((cur + nums[i]) % 2 == 0)
                return -1;
        }
        return cnt;
    }
};
// @lc code=end

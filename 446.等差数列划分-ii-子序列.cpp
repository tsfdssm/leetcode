/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
#define ll long long
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        ll ans = 0;
        vector<unordered_map<ll, int>> cnt(n);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
            {
                ll delta = (ll)nums[i] - (ll)nums[j];
                int sum = 0;
                if (cnt[j].count(delta))
                    sum = cnt[j][delta];
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        return (int)ans;
    }
};
// @lc code=end

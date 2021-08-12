/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<long> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            f[i] = (f[i - 1] * 2) % mod;
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res = (res + (f[i] - f[n - 1 - i]) * nums[i]) % mod;
        }
        return res;
        // map<int, int> mp;
        // for (int num : nums)
        //     mp[num]++;

        // int left = n, right = 0;
        // int res = 0;
        // for (auto it = mp.rbegin(); it != mp.rend(); ++it)
        // {
        //     auto [k, v] = *it;
        //     right += v;
        //     long long cur = k * v * (f[left - 1] - f[right - 1]);
        //     res = (res + cur) % mod;
        //     left -= v;
        // }
        // return res;
    }
};
// @lc code=end

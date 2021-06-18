/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution
{
public:
    bool makesquare(vector<int> &nums)
    {
        // if (!nums.size())
        //     return false;
        // size_t total = accumulate(nums.begin(), nums.end(), size_t{0});

        // int k = 4; // 可更改
        // if (total % k)
        //     return false;
        // size_t target = total / k, len = nums.size();
        // int allused = (1 << len) - 1;
        // // search from the largest to the smallest.
        // sort(nums.rbegin(), nums.rend());
        // if (nums[0] > target)
        //     return false;

        // function<bool(int, int, int)> solve = [&](int state, int sum, int st) {
        //     if (state == allused)
        //         return true;
        //     int max = target - (sum % target);
        //     for (int i = st; i < len; i++)
        //     {
        //         if (state & (1 << i) || nums[i] > max)
        //             continue;
        //         // if this subset is fullfilled, start a new search from the beginning.
        //         if (solve(state | (1 << i), sum + nums[i], nums[i] == max ? 0 : i + 1))
        //             return true;
        //     }
        //     return false;
        // };

        // return solve(0, 0, 0);

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int len = sum / 4;
        if (0 != sum % 4 || nums.back() > len)
            return false;
        if (0 == len)
            return true;
        vector<int> f(1 << n, -1);
        f[0] = 0;
        for (int i = 1; i < (1 << n); ++i)
            for (int j = 0; j < n; ++j)
            {
                int s = i ^ (1 << j);
                if (((i >> j) & 1) && f[s] != -1)
                {
                    int res = len - (f[s] % len);
                    if (nums[j] <= res)
                    {
                        f[i] = f[s] + nums[j];
                        break;
                    }
                }
            }
        return f[(1 << n) - 1] != -1;
    }
};
// @lc code=end

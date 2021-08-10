/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = n + 1;
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];
        deque<int> q;
        for (int i = 0; i <= n; ++i)
        {
            while (!q.empty() && sum[q.back()] >= sum[i])
                q.pop_back();
            while (!q.empty() && sum[q.front()] <= sum[i] - k)
            {
                res = min(res, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return res == n + 1 ? -1 : res;
        // const int inf = 0x3f3f3f3f;
        // int res = inf;
        // int n = nums.size();
        // int sum = 0;
        // int l = 0, r = 0; //开区间
        // while (r < n)
        // {
        //     while (l < r && (sum >= k || nums[l] < 0))
        //     {
        //         if (sum >= k)
        //             res = min(res, r - l);
        //         sum -= nums[l];
        //         ++l;
        //     }
        //     while (r < n && sum < k)
        //     {
        //         sum += nums[r++];
        //         if (sum <= 0)
        //         {
        //             l = r;
        //             sum = 0;
        //         }
        //     }
        // }

        // while (l < r && (sum >= k || nums[l] < 0))
        // {
        //     if (sum >= k)
        //         res = min(res, r - l);
        //     sum -= nums[l];
        //     ++l;
        // }
        // return res == inf ? -1 : res;
    }
};
// @lc code=end

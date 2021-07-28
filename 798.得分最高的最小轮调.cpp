/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        // int N = A.size();
        // vector<int> mark(N, 0);
        // for (int i = 0; i < N; ++i)
        // {
        //     int k_in = (i + 1) % N;             // 得分区间入口
        //     int k_out = (N + i + 1 - A[i]) % N; // 得分区间出口
        //     ++mark[k_in];
        //     --mark[k_out];
        // }
        // int res = 0;
        // int score = 0;
        // int max_score = INT_MIN;
        // for (int i = 0; i < N; ++i)
        // {
        //     score += mark[i]; // 寻找最大累计和，也就是最大重合区间数目
        //     if (score > max_score)
        //     {
        //         res = i;
        //         max_score = score;
        //     }
        // }
        // return res;
        int n = nums.size();
        vector<int> bad(n, 0);
        for (int i = 0; i < n; ++i)
        {
            int left = (i - nums[i] + 1 + n) % n;
            int right = (i + 1) % n;
            bad[left]--;
            bad[right]++;
            if (left > right)
                bad[0]--;
        }
        int best = -n;
        int res = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            cur += bad[i];
            if (cur > best)
            {
                best = cur;
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end

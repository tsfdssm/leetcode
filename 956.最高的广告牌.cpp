/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */

// @lc code=start
class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        // int N = rods.size();
        // int K = accumulate(rods.begin(), rods.end(), 0);
        // vector<int> dp(K + 1, 0);
        // for (int i = 1; i <= N; ++i)
        // {
        //     auto dp1 = dp;
        //     for (int j = 0; j <= K; ++j)
        //     {
        //         // 钢筋高度差为j的时候其加和至少为j，因此不符合条件的跳过
        //         if (dp[j] < j)
        //             continue;
        //         // 加到长的那一侧
        //         int k = j + rods[i - 1];
        //         dp1[k] = max(dp1[k], dp[j] + rods[i - 1]);
        //         // 加到短的那一侧
        //         k = abs(j - rods[i - 1]);
        //         dp1[k] = max(dp1[k], dp[j] + rods[i - 1]);
        //     }
        //     swap(dp, dp1);
        // }
        // return dp[0] / 2;

        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int l = rods[i];
            auto nxt = dp;
            for (int j = 0; j <= sum; ++j)
            {
                if (dp[j] < j)
                    continue;
                nxt[j + l] = max(nxt[j + l], dp[j] + l);
                nxt[abs(l - j)] = max(nxt[abs(l - j)], dp[j] + l);
            }
            dp = move(nxt);
        }
        return dp[0] / 2;

        // unordered_map<int, int> d;
        // d[0] = 0;
        // for (int rod : rods)
        // {
        //     unordered_map<int, int> d1 = d;
        //     for (auto iter = d1.begin(); iter != d1.end(); ++iter)
        //     {
        //         int key = iter->first;
        //         d[key + rod] = max(d[key + rod], iter->second + rod);
        //         d[key - rod] = max(d[key - rod], iter->second);
        //     }
        // }
        // return d[0];
    }
};
// @lc code=end

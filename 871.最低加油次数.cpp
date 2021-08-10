/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (startFuel >= target)
            return 0;
        int n = stations.size();
        //vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        //用二维int dp数组会在提交时发现在一个测试案例中两根整型相加
        //超过了INT_MAX而溢出报错，故这里换用long
        //因不支持vector<vector<long>> dp(n+1,vector<int> (n+1,0));
        //故换用下面四行来实现
        long dp[n + 1][n + 1];
        for (int i = 0; i < n + 1; ++i)
            for (int j = 0; j < n + 1; ++j)
                dp[i][j] = 0; //dp数组初始化

        //开成n+1的长度是因为把起点视为第0个加油站：起始状态处理
        for (int i = 0; i < n + 1; ++i)
            dp[i][0] = startFuel; //甭管经过了几个站，一次油也不加那最多跑的就是startFuel的距离

        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (dp[i - 1][j] >= stations[i - 1][0]) //在第i站不加油
                    dp[i][j] = dp[i - 1][j];
                if (dp[i - 1][j - 1] >= stations[i - 1][0])                          //在第i站加油
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]); //加油与否两种情况取大者
            }
        }

        for (int j = 0; j <= n; ++j)
            if (dp[n][j] >= target)
                return j;
        return -1;
        // if (startFuel >= target)
        //     return 0;
        // int n = stations.size();
        // vector<long> dp(n + 1, 0);
        // dp[0] = startFuel;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int t = i; t >= 0; --t)
        //     {
        //         if (dp[t] >= stations[i][0])
        //             dp[t + 1] = max(dp[t + 1], dp[t] + (long)stations[i][1]);
        //         else
        //             break;
        //     }
        // }
        // for (int i = 0; i <= n; ++i)
        // {
        //     if (dp[i] >= target)
        //         return i;
        // }
        // return -1;
        // if (startFuel >= target)
        //     return 0;
        // int n = stations.size();
        // stations.push_back({target});
        // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1)); //(i,j),经过j次加油到达加油站i的最大剩余油量
        // for (int i = 0; i < n; ++i)
        // {
        //     if (startFuel < stations[i][0])
        //         break;
        //     dp[i][0] = startFuel - stations[i][0];
        // }
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j <= i; ++j)
        //     {
        //         if (-1 == dp[i][j])
        //             continue;
        //         for (int k = i + 1; k <= n; ++k)
        //         {
        //             if (dp[i][j] + stations[i][0] >= stations[k][0])
        //                 dp[k][j] = max(dp[k][j], dp[i][j] + stations[i][0] - stations[k][0]);
        //             if (dp[i][j] + stations[i][0] + stations[i][1] >= stations[k][0])
        //                 dp[k][j + 1] = max(dp[k][j + 1], dp[i][j] + stations[i][0] + stations[i][1] - stations[k][0]);
        //             else
        //                 break;
        //         }
        //     }
        // }
        // for (int i = 0; i <= n; ++i)
        // {
        //     if (dp[n][i] != -1)
        //         return i;
        // }
        // return -1;
    }
};
// @lc code=end

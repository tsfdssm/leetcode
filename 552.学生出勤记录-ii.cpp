/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
class Solution
{
public:
    int checkRecord(int n)
    {

        vector<long> now(6, 1), pre(now);
        now[2] = now[4] = now[5] = 0;
        long mod = 1000000007;
        int res = 3;
        for (int i = 2; i <= n; i++)
        {
            pre = now;
            now[0] = (pre[0] + pre[1] + pre[2]) % mod;
            now[1] = pre[0] % mod;
            now[2] = pre[1] % mod;
            now[3] = (pre[0] + pre[1] + pre[2] + pre[3] + pre[4] + pre[5]) % mod;
            now[4] = pre[3] % mod;
            now[5] = pre[4] % mod;
            if (i == n)
                res = (now[0] + now[1] + now[2] + now[3] + now[4] + now[5]) % mod;
        }
        return res;
    }
};
// @lc code=end

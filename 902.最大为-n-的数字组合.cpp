/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution
{
public:
    int solve(vector<int> &d, int n)
    {
        string s = to_string(n);
        int k = s.size();
        int nd = d.size();
        vector<int> dp(k + 1, 0);
        vector<int> pown(k);
        pown[0] = 1;
        for (int i = 1; i < k; ++i)
            pown[i] = pown[i - 1] * nd;
        dp[k] = 1;
        for (int i = k - 1; i >= 0; --i)
        {
            int v = s[i] - '0';
            for (int j = 0; j < nd; ++j)
            {
                if (d[j] < v)
                    dp[i] += pown[k - i - 1];
                else if (d[j] == v)
                    dp[i] += dp[i + 1];
            }
        }
        for (int i = 1; i < k; ++i)
        {
            dp[0] += pown[i];
        }
        return dp[0];
        // if (n < 10)
        //     return upper_bound(d.begin(), d.end(), n) - d.begin();
        // int maxd = d.back();

        // int cnt = d.size();
        // int k = 1;
        // int res = 0;
        // int idx = 1;
        // long long maxn = maxd;
        // while (maxn <= n)
        // {
        //     k *= cnt;
        //     res += k;

        //     idx *= 10;
        //     maxn *= 10;
        //     maxn += maxd;
        // }
        // int l = n / idx;
        // for (int i = 0; i < d.size(); ++i)
        // {
        //     if (d[i] > l)
        //         break;
        //     else if (d[i] == l)
        //     {
        //         if (idx == 1)
        //             res += 1;
        //         else
        //             res += solve(d, n % idx);
        //         break;
        //     }
        //     else
        //     {
        //         res += k;
        //     }
        // }
        // return res;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {

        vector<int> d;
        for (string &s : digits)
            d.emplace_back(s[0] - '0');
        //sort(d.begin(), d.end());
        return solve(d, n);
    }
};
// @lc code=end

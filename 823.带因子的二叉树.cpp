/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        const int mod = 1e9 + 7;

        sort(arr.begin(), arr.end());
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[arr[i]] = i;

        vector<long long> dp(n, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int tmp = arr[i] / arr[j];
                    if (tmp == arr[j])
                    {
                        dp[i] += (dp[j] * dp[j] + mod) % mod;
                        dp[i] %= mod;
                    }
                    else if (mp.count(tmp))
                    {
                        dp[i] += (dp[mp[tmp]] * dp[j] + mod) % mod;
                        dp[i] %= mod;
                    }
                    else
                    {
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};
// @lc code=end

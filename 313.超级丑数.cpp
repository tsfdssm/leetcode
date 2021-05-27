/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        if (0 == n)
            return 0;
        if (1 == n)
            return 1;
        int m = primes.size();

        vector<int> dp(n);
        dp[0] = 1;

        vector<int> p(m, 0);
        vector<int> nums(m, 0);
        for (int i = 1; i < n; ++i)
        {
            int minN = INT_MAX;
            for (int j = 0; j < m; ++j)
            {
                nums[j] = dp[p[j]] * primes[j];
                if (nums[j] < minN)
                    minN = nums[j];
            }
            dp[i] = minN;
            for (int j = 0; j < m; ++j)
                if (dp[i] == nums[j])
                    p[j]++;
        }
        return dp[n - 1];
    }
};
// @lc code=end

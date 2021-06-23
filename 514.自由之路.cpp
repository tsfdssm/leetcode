/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        int m = key.size();
        vector<int> pos[26];
        for (int i = 0; i < n; ++i)
            pos[ring[i] - 'a'].push_back(i);
        vector<int> dp(n, 0x3f3f3f3f);

        //vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        for (auto &i : pos[key[0] - 'a'])
            dp[i] = min(i, n - i) + 1;
        vector<int> bk;
        bk.assign(dp.begin(), dp.end());
        for (int i = 1; i < m; ++i)
        {
            for (auto &j : pos[key[i] - 'a'])
            {
                for (auto &k : pos[key[i - 1] - 'a'])
                {
                    dp[j] = min(dp[j], bk[k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
            bk.assign(dp.begin(), dp.end());
        }
        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

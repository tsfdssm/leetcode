/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution
{
public:
    const int INF = 0x3f3f3f3f;
    int minStickers(vector<string> &stickers, string target)
    {
        vector<int> dp(1 << 15, INF);
        int n = stickers.size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26));
        vector<vector<int>> can(26);
        for (int i = 0; i < n; ++i)
            for (char c : stickers[i])
            {
                int d = c - 'a';
                cnt[i][d]++;
                if (can[d].empty() || can[d].back() != i)
                    can[d].emplace_back(i);
            }
        dp[0] = 0;
        for (int i = 0; i < (1 << m) - 1; ++i)
        {
            if (dp[i] == INF)
                continue;
            int d;
            for (int j = 0; j < m; ++j)
            {
                if (!(i & (1 << j)))
                {
                    d = j;
                    break;
                }
            }
            d = target[d] - 'a';
            for (int k : can[d])
            {
                int nxt = i;
                vector<int> left(cnt[k]);
                for (int j = 0; j < m; ++j)
                {
                    if (nxt & (1 << j))
                        continue;
                    if (left[target[j] - 'a'] > 0)
                    {
                        nxt += (1 << j);
                        left[target[j] - 'a']--;
                    }
                    dp[nxt] = min(dp[nxt], dp[i] + 1);
                }
            }
        }
        return dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1];
    }
};
// @lc code=end

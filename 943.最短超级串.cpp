/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */

// @lc code=start
class Solution
{
public:
    int getOverlap(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        int t = min(n, m);
        for (int i = t; i > 0; --i)
        {
            string at = a.substr(n - i, i);
            string bt = b.substr(0, i);
            if (at == bt)
                return i;
        }
        return 0;
        //Wrong
        // int m = a.size();
        // int n = b.size();
        // int t = min(m, n);
        // for (int i = 0; i < t; ++i)
        // {
        //     if (a[m - 1 - i] != b[i])
        //     {
        //         return i;
        //     }
        // }
        // return t;
    }
    string shortestSuperstring(vector<string> &words)
    {
        string res;
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                    continue;
                overlap[i][j] = getOverlap(words[i], words[j]);
            }
            res += words[i];
        }
        int maxL = res.size();
        vector<vector<string>> dp(1 << n, vector<string>(n, res));
        for (int state = 1; state < (1 << n); ++state)
        {
            for (int j = 0; j < n; ++j)
            {
                if (state && (1 << j))
                {
                    int preState = (state ^ (1 << j));
                    if (0 == preState)
                        dp[state][j] = words[j];
                    else
                    {
                        for (int i = 0; i < n; ++i)
                        {
                            if (state & (1 << i))
                            {
                                if (i == j)
                                    continue;
                                int t = dp[preState][i].size() + words[j].size() - overlap[i][j];
                                if (dp[state][j].size() > t)
                                    dp[state][j] = dp[preState][i] + words[j].substr(overlap[i][j]);
                            }
                        }
                    }
                }
            }
        }
        // uint32_t endNum = (1 << n) - 1;
        // for (int i = 0; i < n; i++)
        // {
        //     string s = dp[endNum][i];
        //     if (res.size() > s.size())
        //         res = s;
        // }
        // return res;
        uint32_t maxn = (1 << n) - 1;
        int resl = maxL;
        int resi = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[maxn][i].size() < resl)
            {
                resl = dp[maxn][i].size();
                resi = i;
            }
        }
        return dp[maxn][resi];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
 */

// @lc code=start
class Solution
{
public:
    int knightDialer(int n)
    {
        const int mod = 1e9 + 7;
        auto in_grid = [&](int x, int y) -> bool {
            return 0 <= x && x < 4 && 0 <= y && y < 3; //&& !(3 == x && (0 == y) || (2 == y));
        };
        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        vector<vector<long>> dp(4, vector<long>(3, 1));
        dp[3][0] = dp[3][2] = 0;
        for (int i = 1; i < n; ++i)
        {
            vector<vector<long>> nxt(4, vector<long>(3, 0));
            //auto nxt = dp;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 3; ++j)
                    if (!in_grid(i, j))
                        continue;
                    else
                        for (int k = 0; k < 8; ++k)
                        {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (!in_grid(ni, nj))
                                continue;
                            if (3 == ni && ((0 == nj) || (2 == nj)))
                                continue;
                            nxt[ni][nj] = (nxt[ni][nj] + dp[i][j]) % mod;
                        }
            dp = move(nxt);
        }
        long res = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                res = (res + dp[i][j]) % mod;
        return res;
    }
};
// @lc code=end

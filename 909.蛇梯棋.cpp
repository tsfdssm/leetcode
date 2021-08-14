/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        //vector<int> vis(n * n + 1);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        function<pair<int, int>(int)> pos = [&](int x) {
            int i = (x - 1) / n;
            int j = (x - 1) % n;
            if (i % 2 == 1)
                j = n - 1 - j;
            i = n - 1 - i;
            return make_pair(i, j);
        };
        // queue<pair<int, int>> q;
        // q.push({1, 0});
        // int res = 0;
        // int target = n * n;
        // while (!q.empty())
        // {
        //     int len = q.size();
        //     auto [cur, d] = q.front();
        //     q.pop();
        //     // if (cur == target)
        //     //     return d;
        //     for (int k = 1; k <= 6; ++k)
        //     {
        //         int next = cur + k;
        //         if (next > target)
        //             break;
        //         auto [x, y] = pos(next);

        //         if (board[x][y] > 0)
        //         {
        //             next = board[x][y];
        //         }
        //         if (vis[next])
        //             continue;
        //         vis[next] = 1;
        //         vis[next] = 1;
        //         if (next == target)
        //             return d + 1;
        //         q.push({next, d + 1});
        //     }
        // }
        queue<int> q;
        q.push(1);
        int res = 0;
        int target = n * n;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto cur = q.front();
                q.pop();
                if (cur == target)
                    return res;
                for (int k = 1; k <= 6; ++k)
                {
                    int next = cur + k;
                    if (next > target)
                        break;
                    // if (next == target)
                    //     return res + 1;
                    auto [x, y] = pos(next);
                    if (board[x][y] != -1)
                    {
                        next = board[x][y];
                        tie(x, y) = pos(board[x][y]);
                    }
                    if (vis[x][y])
                        continue;
                    vis[x][y] = 1;
                    q.push(next);
                }
            }
            ++res;
        }
        return -1;
    }
};
// @lc code=end

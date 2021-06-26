/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution
{
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void bfs(vector<vector<char>> &board, int sx, int sy)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        q.push({sx, sy});
        vis[sx][sy] = true;
        while (!q.empty())
        {
            auto &pos = q.front();
            int cnt = 0;
            int x = pos.first, y = pos.second;
            q.pop();
            for (int i = 0; i < 8; ++i)
            {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size())
                    continue;
                cnt += board[tx][ty] == 'M';
            }
            if (cnt > 0)
                board[x][y] = cnt + '0';
            else
            {
                board[x][y] = 'B';
                for (int i = 0; i < 8; ++i)
                {
                    int tx = x + dir_x[i];
                    int ty = y + dir_y[i];
                    if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E' || vis[tx][ty])
                        continue;
                    q.push({tx, ty});
                    vis[tx][ty] = true;
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M')
            board[x][y] = 'X';
        else
            bfs(board, x, y);
        return board;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        if (0 == m)
            return;
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                int cnt = 0;
                if (isOk(i - 1, j - 1, m, n) && nowLive(board[i - 1][j - 1]))
                    cnt++;
                if (isOk(i - 1, j, m, n) && nowLive(board[i - 1][j]))
                    cnt++;
                if (isOk(i - 1, j + 1, m, n) && nowLive(board[i - 1][j + 1]))
                    cnt++;
                if (isOk(i, j - 1, m, n) && nowLive(board[i][j - 1]))
                    cnt++;
                if (isOk(i, j + 1, m, n) && nowLive(board[i][j + 1]))
                    cnt++;
                if (isOk(i + 1, j - 1, m, n) && nowLive(board[i + 1][j - 1]))
                    cnt++;
                if (isOk(i + 1, j, m, n) && nowLive(board[i + 1][j]))
                    cnt++;
                if (isOk(i + 1, j + 1, m, n) && nowLive(board[i + 1][j + 1]))
                    cnt++;
                if (0 == board[i][j])
                {
                    if (3 == cnt)
                        board[i][j] = 'd';
                    else
                        board[i][j] = 'c';
                }
                else
                {
                    if (2 == cnt || 3 == cnt)
                        board[i][j] = 'b';
                    else
                        board[i][j] = 'a';
                }
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if ('b' == board[i][j] || 'd' == board[i][j])
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
    }

    inline bool nowLive(int i)
    {
        if (1 == i || i == 'a' || i == 'b')
            return true;
        return false;
    }
    inline bool isOk(int i, int j, int m, int n)
    {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ('R' == board[i][j])
                {
                    int x = i;
                    int y = j;
                    for (--x; x >= 0; --x)
                    {
                        if ('.' == board[x][y])
                            continue;
                        else
                        {
                            if ('p' == board[x][y])
                                ++cnt;
                            break;
                        }
                    }
                    x = i;
                    y = j;
                    for (++x; x < m; ++x)
                    {
                        if ('.' == board[x][y])
                            continue;
                        else
                        {
                            if ('p' == board[x][y])
                                ++cnt;
                            break;
                        }
                    }
                    x = i;
                    y = j;
                    for (--y; y >= 0; --y)
                    {
                        if ('.' == board[x][y])
                            continue;
                        else
                        {
                            if ('p' == board[x][y])
                                ++cnt;
                            break;
                        }
                    }
                    x = i;
                    y = j;
                    for (++y; y < n; ++y)
                    {
                        if ('.' == board[x][y])
                            continue;
                        else
                        {
                            if ('p' == board[x][y])
                                ++cnt;
                            break;
                        }
                    }
                    return cnt;
                }
        return -1;
    }
};
// @lc code=end

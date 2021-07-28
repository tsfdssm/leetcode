/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int cnto = 0;
        int cntx = 0;
        vector<int> rowx(3, 0);
        vector<int> colx(3, 0);
        vector<int> rowo(3, 0);
        vector<int> colo(3, 0);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                char c = board[i][j];
                if (' ' == c)
                {
                }
                else if ('X' == c)
                {
                    cntx++;
                    rowx[i]++;
                    colx[j]++;
                }
                else
                {
                    cnto++;
                    rowo[i]++;
                    colo[j]++;
                }
            }
        if (cntx != cnto && (cntx != cnto + 1))
            return false;
        bool x = false;
        bool o = false;
        int cnt_row = 0;
        for (int i = 0; i < 3; ++i)
            if (rowx[i] == 3)
            {
                cnt_row++;
                x = true;
            }
            else if (rowo[i] == 3)
            {
                cnt_row++;
                o = true;
            }
            else
            {
            }
        if (cnt_row >= 2)
            return false;

        int cnt_col = 0;
        for (int i = 0; i < 3; ++i)
            if (colx[i] == 3)
            {
                cnt_col++;
                x = true;
            }
            else if (colo[i] == 3)
            {
                cnt_col++;
                o = true;
            }
            else
            {
            }
        if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        {
            if (board[0][0] == 'X')
            {
                x = true;
            }
            else if (board[0][0] == 'O')
            {
                o = true;
            }
        }

        if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
        {
            if (board[0][2] == 'X')
            {
                x = true;
            }
            else if (board[0][2] == 'O')
            {
                o = true;
            }
        }
        if (cnt_col >= 2)
            return false;
        if (x && o)
            return false;
        if (cntx == cnto && x)
            return false;
        if (cntx == (cnto + 1) && o)
            return false;
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
private:
    int row[9];
    int col[9];
    int box[3][3];
    bool valid;
    vector<pair<int, int>> point;

public:
    void flip(int i, int j, int digit)
    {
        row[i] ^= 1 << digit;
        col[j] ^= 1 << digit;
        box[i / 3][j / 3] ^= 1 << digit;
    }
    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == point.size())
        {
            valid = true;
            return;
        }
        else
        {
            auto [i, j] = point[pos];
            int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1ff;
            for (; mask && !valid; mask &= mask - 1)
            {
                int digitmask = mask & (-mask);
                int digit = __builtin_ctz(digitmask);

                flip(i, j, digit);
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                flip(i, j, digit);
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        valid = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    point.emplace_back(i, j);
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
                }
        }
        dfs(board, 0);
    }
};
// @lc code=end

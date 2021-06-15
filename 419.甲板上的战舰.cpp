/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int res = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'X' && (i == m - 1 || board[i + 1][j] != 'X') && (j == n - 1 || board[i][j + 1] != 'X'))
                    ++res;
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start

#include <unordered_map>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, int> row[9];
        unordered_map<int, int> col[9];
        unordered_map<int, int> box[9];

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                int val = board[i][j] - '0';
                int box_index = (i / 3) * 3 + j / 3;

                // row[i][val]++;
                // col[j][val]++;
                // box[box_index][val]++;
                if (++row[i][val] == 2 || ++col[j][val] == 2 || ++box[box_index][val] == 2)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

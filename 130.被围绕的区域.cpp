/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution
{
public:
    vector<vector<bool>> vis;
    int m = 0, n = 0;
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if ('O' != board[i][j] || vis[i][j] == true)
            return;
        vis[i][j] = true;
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        vis.resize(m, vector<bool>(n, false));
        if (1 == m || 1 == n)
            return;
        for (int i = 0; i < n; ++i)
        {
            if (false == vis[0][i])
                dfs(0, i, board);
            if (false == vis[m - 1][i])
                dfs(m - 1, i, board);
        }
        for (int i = 1; i < m - 1; ++i)
        {
            if (false == vis[i][0])
                dfs(i, 0, board);
            if (false == vis[i][n - 1])
                dfs(i, n - 1, board);
        }
        //         dfs(m - 1, n - 1 - i, board);
        // for (int i = 0; i < n - 1; ++i)
        // {
        //     if (false == vis[0][i])
        //         dfs(0, i, board);
        // }
        // for (int i = 0; i < m - 1; ++i)
        // {
        //     if (false == vis[i][n - 1])
        //         dfs(i, n - 1, board);
        // }
        // for (int i = 0; i < n - 1; ++i)
        // {
        //     if (false == vis[m - 1][n - 1 - i])
        //         dfs(m - 1, n - 1 - i, board);
        // }
        // for (int i = 0; i < m - 1; ++i)
        // {
        //     if (false == vis[m - 1 - i][0])
        //         dfs(m - 1 - i, 0, board);
        // }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) //&& board[i][j] != 'X'
            {
                if (true != vis[i][j])
                    board[i][j] = 'X';
            }
        return;
    }
};
// @lc code=end

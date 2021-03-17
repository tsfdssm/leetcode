/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<bool> row;
    vector<bool> col;
    vector<bool> edge1;
    vector<bool> edge2;
    vector<vector<bool>> tmp;
    vector<vector<string>> res;

    int N;
    void backtrack(int n)
    {
        if (n == N)
        {
            output();
            return;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                if (col[i] || edge1[n - i + N - 1] || edge2[n + i])
                    continue;
                col[i] = true;
                edge1[n - i + N - 1] = true;
                edge2[n + i] = true;
                tmp[n][i] = true;
                backtrack(n + 1);
                col[i] = false;
                edge1[n - i + N - 1] = false;
                edge2[n + i] = false;
                tmp[n][i] = false;
            }
        }
        return;
    }
    void output()
    {
        vector<string> str(N, string(N, '.'));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (tmp[i][j])
                    str[i][j] = 'Q';
            }
        }
        res.push_back(str);
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        row.resize(n, false);
        col.resize(n, false);
        edge1.resize(2 * n - 1, false);
        edge2.resize(2 * n - 1, false);
        tmp.resize(n, vector<bool>(n, false));
        backtrack(0);
        return res;
    }
};
// @lc code=end

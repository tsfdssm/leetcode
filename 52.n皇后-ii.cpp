/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution
{
private:
    vector<bool> row;
    vector<bool> col;
    vector<bool> edge1;
    vector<bool> edge2;
    vector<vector<bool>> tmp;
    int res;

    int N;
    void backtrack(int n)
    {
        if (n == N)
        {
            res++;
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

public:
    int totalNQueens(int n)
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

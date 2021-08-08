/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 */

// @lc code=start
class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        vector<int> x(2, 0);

        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i <= m - 3; ++i)
            for (int j = 0; j <= n - 3; ++j)
            {
                fill(rows.begin(), rows.end(), 0);
                fill(cols.begin(), cols.end(), 0);
                x[0] = x[1] = 0;
                bool flag = true;
                set<int> st;
                for (int tmpi = i; flag && tmpi < i + 3; ++tmpi)
                    for (int tmpj = j; tmpj < j + 3; ++tmpj)
                    {
                        if (grid[tmpi][tmpj] <= 0 || 9 < grid[tmpi][tmpj])
                        {
                            flag = false;
                            break;
                        }
                        st.insert(grid[tmpi][tmpj]);
                        rows[tmpi - i] += grid[tmpi][tmpj];
                        cols[tmpj - j] += grid[tmpi][tmpj];
                        if (tmpi - i == tmpj - j)
                            x[0] += grid[tmpi][tmpj];
                        if (2 == (tmpi - i) + (tmpj - j))
                            x[1] += grid[tmpi][tmpj];
                    }
                if (!flag || 9 != st.size())
                    continue;
                int val = rows[0];
                if (rows[1] != val || rows[2] != val)
                    continue;
                if (cols[0] != val || cols[1] != val || cols[2] != val)
                    continue;
                if (x[0] != val || x[1] != val)
                    continue;
                res++;
            }

        return res;
    }
};
// @lc code=end

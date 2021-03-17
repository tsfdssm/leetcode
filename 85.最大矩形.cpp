/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (0 == matrix.size())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ('1' == matrix[i][j])
                    left[i][j] = j == 0 ? 1 : (left[i][j - 1] + 1);
        int res = 0;

        for (int j = 0; j < n; j++)
        {
            vector<int> up(m, 0), down(m, m);
            stack<int> st;
            for (int i = 0; i < m; i++)
            {
                while (!st.empty() && left[st.top()][j] >= left[i][j])
                {
                    down[st.top()] = i;
                    st.pop();
                }
                up[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            for (int i = 0; i < m; i++)
                res = max(res, (down[i] - up[i] - 1) * left[i][j]);
        }
        return res;
    }
};
// @lc code=end

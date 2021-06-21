/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int k = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto cur = q.front();
                if (cur.first < m && cur.second < n)
                    res.push_back(mat[cur.first][cur.second]);
                q.pop();
                if (0 == i)
                {
                    if (cur.first < m - 1)
                        q.push({cur.first + 1, cur.second});
                }
                if (cur.second < n - 1)
                    q.push({cur.first, cur.second + 1});
            }
            if ((k & 1) == 1 && len > 1)
                reverse(res.begin() + res.size() - len, res.end());
            ++k;
        }
        return res;
    }
};
// @lc code=end

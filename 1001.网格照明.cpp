/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        int Row = n;
        int Col = n;
        int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        unordered_map<int, int> row_dic;
        unordered_map<int, int> col_dic;
        unordered_map<int, int> diag_dic;
        unordered_map<int, int> anti_diag_dic;
        set<pair<int, int>> lamp_set;
        for (auto &v : lamps)
        {
            int r = v[0], c = v[1];
            if (lamp_set.find({r, c}) != lamp_set.end()) //一个数据坑！！！！！！！！！！！！
                continue;
            row_dic[r]++;
            col_dic[c]++;
            diag_dic[r - c]++;
            anti_diag_dic[r + c]++;
            lamp_set.insert({r, c});
        }
        vector<int> res;
        for (auto &q : queries)
        {
            int r = q[0], c = q[1];
            if (row_dic[r] > 0 || col_dic[c] > 0 || diag_dic[r - c] > 0 || anti_diag_dic[r + c] > 0)
                res.push_back(1);
            else
                res.push_back(0);
            for (int i = 0; i < 9; ++i)
            {
                int nr = r + dx[i], nc = c + dy[i];
                if (0 <= nr && nr < Row && 0 <= nc && nc < Col)
                {
                    if (lamp_set.count({nr, nc}))
                    {
                        lamp_set.erase({nr, nc});
                        row_dic[nr]--;
                        col_dic[nc]--;
                        diag_dic[nr - nc]--;
                        anti_diag_dic[nr + nc]--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

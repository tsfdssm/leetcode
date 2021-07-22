/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, int> mp;
    vector<vector<int>> nxt = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    void dfs(string num, int cnt, int idx)
    {
        if (mp.count(num) && mp[num] <= cnt)
            return;
        mp[num] = cnt;
        for (int i = 0; i < nxt[idx].size(); ++i)
        {
            string tmp = num;
            swap(tmp[idx], tmp[nxt[idx][i]]);
            dfs(tmp, cnt + 1, nxt[idx][i]);
        }
    }
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string st;
        int idx = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
            {
                st += board[i][j] + '0';
                if (board[i][j] == 0)
                    idx = i * 3 + j;
            }
        dfs(st, 0, idx);
        if (!mp.count("123450"))
            return -1;
        return mp["123450"];
    }
};
// @lc code=end

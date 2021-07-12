/*
 * @lc app=leetcode.cn id=749 lang=cpp
 *
 * [749] 隔离病毒
 */

// @lc code=start
class Solution
{
public:
    int containVirus(vector<vector<int>> &isInfected)
    {
        int dir_i[4] = {0, 0, 1, -1};
        int dir_j[4] = {1, -1, 0, 0};
        int m = isInfected.size();
        int n = isInfected[0].size();
        queue<pair<int, int>> q;
        int wall = 0;
        int vis[m][n];
        auto bfs = [&](int i, int j, bool update, bool infect) -> pair<int, int> {
            int cnt = 0, cntWall = 0;
            q.push({i, j});
            vis[i][j] = (i * n + j) + 1;
            while (!q.empty())
            {
                auto [ci, cj] = q.front();
                q.pop();
                if (update)
                    isInfected[ci][cj] = -1;
                for (int k = 0; k < 4; ++k)
                {
                    int tmpi = ci + dir_i[k];
                    int tmpj = cj + dir_j[k];
                    if (tmpi < 0 || m <= tmpi || tmpj < 0 || n <= tmpj)
                        continue;
                    if (isInfected[tmpi][tmpj] == 0)
                    {
                        ++cntWall;
                        if (vis[tmpi][tmpj] != (i * n + j + 1))
                        {
                            vis[tmpi][tmpj] = (i * n + j + 1);
                            cnt++;
                            if (infect)
                                isInfected[tmpi][tmpj] = 1;
                        }
                    }
                    else if (isInfected[tmpi][tmpj] == 1 && vis[tmpi][tmpj] == 0)
                    {
                        vis[tmpi][tmpj] = (i * n + j + 1);
                        q.push({tmpi, tmpj});
                    }
                }
            }
            return {cnt, cntWall};
        };
        while (1)
        {
            int maxCurArea = 0;
            int curWall = 0;
            auto [si, sj] = make_pair(-1, -1);
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                {
                    int tmpArea = 0, tmpWall = 0;
                    if (1 == isInfected[i][j] && !vis[i][j])
                    {
                        tie(tmpArea, tmpWall) = bfs(i, j, false, false);
                        if (tmpArea > maxCurArea)
                        {
                            maxCurArea = tmpArea;
                            curWall = tmpWall;
                            tie(si, sj) = {i, j};
                        }
                    }
                }
            if (maxCurArea == 0)
                break;
            wall += curWall;
            memset(vis, 0, sizeof(vis));
            bfs(si, sj, true, false);
            memset(vis, 0, sizeof(vis));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (1 == isInfected[i][j] && !vis[i][j])
                        bfs(i, j, false, true);
        }
        return wall;
    }
};
// @lc code=end

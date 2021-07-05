/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
int f[3000], vis[3000], n2;
int q[3000], st[3000];
int tr[3000];
class Solution
{
public:
    int cutOffTree(vector<vector<int>> &forest)
    {
        int m = forest.size();
        int n = forest[0].size();
        n2 = n + 2;
        int sz = n2 * (m + 2);
        int cnt = 0;
        memset(f, 0, sz * sizeof(int));
        memset(vis, 0, sz * sizeof(int));
        tr[cnt++] = n + 3;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                sz = (i + 1) * n2 + j + 1;
                f[sz] = forest[i][j];
                if (f[sz] > 1)
                    tr[cnt++] = sz;
            }
        sort(tr + 1, tr + cnt, [](const int &a, const int &b) { return f[a] < f[b]; });
        int res = 0, t[2];
        for (int i = (tr[0] == tr[1]) ? 2 : 1; i < cnt; i += 2)
        {
            t[0] = tr[i - 1], t[1] = ((i + 1 == cnt) ? -1 : tr[i + 1]);
            if (!bfs(i, tr[i], t, 1 + (t[1] != -1), res))
                return -1;
        }
        return res;
    }

    bool bfs(int num, int s, int t[], int obj, int &res)
    {
        int got = 0, go[4] = {1, -1, n2, -n2};
        q[0] = s, st[0] = 0, vis[s] = num;
        for (int r = 0, w = 1; r != w; ++r)
            for (int d = 0; d < 4; ++d)
            {
                int nxt = q[r] + go[d];
                if (f[nxt] && vis[nxt] != num)
                {
                    if (nxt == t[0])
                        res += st[r] + 1, ++got;
                    if (nxt == t[1])
                        res += st[r] + 1, ++got;
                    if (obj == got)
                        return true;
                    vis[nxt] = num;
                    q[w] = nxt;
                    st[w] = st[r] + 1;
                    ++w;
                }
            }
        return false;
    }
};
// @lc code=end

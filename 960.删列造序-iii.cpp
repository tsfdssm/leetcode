/*
 * @lc app=leetcode.cn id=960 lang=cpp
 *
 * [960] 删列造序 III
 */

// @lc code=start
// class UnionFind
// {
// public:
//     vector<int> f;
//     vector<int> size;
//     UnionFind(int n)
//     {
//         f.resize(n);
//         for (int i = 0; i < n; ++i)
//             f[i] = i;
//         size.resize(n, 1);
//     }

//     int find(int x)
//     {
//         if (x == f[x])
//             return x;
//         return f[x] = find(f[x]);
//     }

//     void merge(int x.int y)
//     {
//         if (find(x) == find(y))
//             return;
//         f[find(y)] = find(x);
//         size[find(x)] += size[find(y)];
//     }

//     int count(int x)
//     {
//         return size[find(x)];
//     }
// };
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int row = strs.size();
        int col = strs[0].size();
        vector<int> dp(col + 1, 1);
        for (int i = 0; i < col; ++i)
        {
            for (int j = i + 1; j < col; ++j)
            {
                bool flag = true;
                for (int k = 0; k < row; ++k)
                {
                    if (strs[k][i] > strs[k][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        return col - *max_element(dp.begin(), dp.end());
        // int n = strs.size();
        // int m = strs[0].size();
        // set<int> st;
        // UnionFind uf(m);
        // for (int i = 0; i < n; ++i)
        // {
        //     string &s = strs[i];
        //     for (int j = 0; j < m; ++j)
        //     {
        //     }
        // }
        // int mind = m;
        // for (auto d : st)
        // {
        //     mind = min(mind, uf.count(d));
        // }
        // if (m == mind)
        //     return 0;
        // return mind;
    }
};
// @lc code=end

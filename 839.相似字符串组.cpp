/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> f;
    UnionFind(int n)
    {
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = i;
    }

    int find(int x)
    {
        if (x == f[x])
            return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        f[find(y)] = find(x);
    }

    bool same(int x, int y)
    {
        return f[x] == f[y];
    }

    int count()
    {
        int cnt = 0;
        for (int i = 0; i < f.size(); ++i)
            if (f[i] == i)
                cnt++;
        return cnt;
    }
};
class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                if (uf.same(i, j))
                    continue;
                if (isSame(strs[i], strs[j]))
                    uf.merge(i, j);
            }
        return uf.count();
    }

    bool isSame(const string &a, const string &b)
    {
        int cnt = 0;
        if (a.size() != b.size())
            return false;
        int n = a.size();
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
                cnt++;
            if (cnt > 2)
                return false;
        }
        return true;
    }
};
// @lc code=end

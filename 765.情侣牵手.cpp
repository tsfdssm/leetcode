/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Unionfind
{
public:
    vector<int> f;
    int _size;
    Unionfind(int n)
    {
        _size = n;
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = i;
    }

    int find(int x)
    {
        if (f[x] == x)
            return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        f[find(y)] = find(x);
    }

    int count()
    {
        int cnt = 0;
        for (int i = 0; i < _size; ++i)
            if (f[i] == i)
                cnt++;
        return cnt;
    }
};
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size() / 2;
        Unionfind uf(2 * n);
        for (int i = 0; i < 2 * n; i += 2)
            uf.merge(i, i + 1);

        for (int i = 0; i < 2 * n; i += 2)
            uf.merge(row[i], row[i + 1]);

        return n - uf.count();
    }
};
// @lc code=end

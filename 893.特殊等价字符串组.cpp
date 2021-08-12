/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
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
        if (isSame(x, y))
            return;
        f[find(y)] = find(x);
    }

    bool isSame(int x, int y)
    {
        return f[x] == f[y];
    }

    int cnt()
    {
        int res = 0;
        for (int i = 0; i < f.size(); ++i)
            if (f[i] == i)
                ++res;
        return res;
    }
};
class Solution
{
public:
    bool check(const string &a, const string &b)
    {
        int n = a.size();
        vector<int> cnt0(26, 0);
        vector<int> cnt1(26, 0);
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                cnt0[a[i] - 'a']++;
                cnt0[b[i] - 'a']--;
            }
            else
            {
                cnt1[a[i] - 'a']++;
                cnt1[b[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; ++i)
            if (cnt0[i] != 0 || cnt1[i] != 0)
                return false;
        return true;
    }
    int numSpecialEquivGroups(vector<string> &words)
    {
        int n = words.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                if (uf.isSame(i, j))
                    continue;
                if (check(words[i], words[j]))
                    uf.merge(i, j);
            }
        return uf.cnt();
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start

class Solution
{
public:
    vector<int> f;
    int find(int x)
    {
        if (x == f[x])
            return x;
        return f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        if (find(x) == find(y))
            return;
        f[find(y)] = find(x);
    }
    bool equationsPossible(vector<string> &equations)
    {
        int idx = 0;
        map<char, int> mp;
        for (string &s : equations)
        {
            int x;
            int y;
            if (mp.count(s[0]))
            {
                x = mp[s[0]];
            }
            else
            {
                x = mp[s[0]] = idx;
                f.emplace_back(idx);
                ++idx;
            }
            if (mp.count(s[3]))
            {
                y = mp[s[3]];
            }
            else
            {
                y = mp[s[3]] = idx;
                f.emplace_back(idx);
                ++idx;
            }
            if ('!' == s[1])
                continue;
            merge(x, y);
        }
        for (string &s : equations)
        {
            if ('=' == s[1])
                continue;
            int x = mp[s[0]];
            int y = mp[s[3]];
            if (find(x) == find(y))
                return false;
        }
        return true;
    }
};
// @lc code=end

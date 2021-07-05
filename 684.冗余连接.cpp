/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> tree;

    void init(int len)
    {
        tree.resize(len);
        for (int i = 0; i < len; ++i)
            tree[i] = i;
    }
    int find(int x)
    {
        if (x == tree[x])
            return x;
        return tree[x] = find(tree[x]);
    }

    void merge(int x, int y)
    {
        if (y < x)
            swap(x, y);
        tree[find(y)] = find(x);
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        init(n + 1);
        int u, v;
        for (const auto &e : edges)
        {
            int tmpu = e[0];
            int tmpv = e[1];
            if (find(tmpv) != find(tmpu))
            {
                merge(tmpu, tmpv);
            }
            else
            {
                u = tmpu;
                v = tmpv;
            }
        }
        return {u, v};
    }
};
// @lc code=end

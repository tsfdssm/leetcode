/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution
{
public:
    vector<int> tree;

    int find(int x)
    {
        return tree[x] == x ? tree[x] : (tree[x] = find(tree[x]));
    }

    void Merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        tree[fy] = fx;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        tree.resize(n);
        for (int i = 0; i < n; ++i)
            tree[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j] == 1)
                    Merge(i, j);
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (tree[i] == i)
                ++res;
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

// @lc code=start
class Solution
{
public:
    bool isSelfCrossing(vector<int> &dist)
    {
        if (dist.size() < 4)
            return false;
        int i = 2, n = dist.size();
        while (i < n && dist[i] > dist[i - 2])
            ++i;
        if (i == n)
            return false;

        if (3 == i && dist[3] == dist[1] || i >= 4 && dist[i - 2] <= dist[i] + dist[i - 4])
            dist[i - 1] -= dist[i - 3];
        while (++i < n && dist[i] < dist[i - 2])
            ;
        return i != n;
    }
};
// @lc code=end

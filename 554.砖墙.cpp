/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> cnt;
        for (const auto &width : wall)
        {
            int sum = 0;
            int n = width.size();
            for (int i = 0; i < n - 1; ++i)
            {
                sum += width[i];
                cnt[sum]++;
            }
        }
        int maxn = 0;
        for (auto &it : cnt)
        {
            maxn = max(maxn, it.second);
        }
        return wall.size() - maxn;
    }
};
// @lc code=end

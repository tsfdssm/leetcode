/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */
#include <queue>
// @lc code=start
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int minN = INT_MAX;
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        vector<int> vis(n);
        for (int i = 0; i < n; ++i)
        {
            auto &vec = nums[i];
            q.push({vec.back(), i});
            minN = min(minN, vec.back());
            vis[i] = vec.size() - 1;
        }
        pair<int, int> res = {0, INT_MAX};
        while (1)
        {

            int idx = q.top().second;
            int maxN = q.top().first;
            q.pop();

            if ((res.second - res.first) >= (maxN - minN))
                res = {minN, maxN};

            if (0 == vis[idx])
                break;
            // if (nums[idx][0] == maxN)
            //     break;
            --vis[idx];
            int nxt = nums[idx][vis[idx]];
            minN = min(minN, nxt);
            q.push({nxt, idx});
        }
        return {res.first, res.second};
    }
};
// @lc code=end

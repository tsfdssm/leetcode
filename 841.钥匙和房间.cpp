/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        int cnt = 1;
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto v : rooms[cur])
            {
                if (vis[v])
                    continue;
                vis[v] = 1;
                ++cnt;
                q.push(v);
            }
        }

        return cnt == n;
    }
};
// @lc code=end

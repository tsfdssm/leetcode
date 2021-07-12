/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<int> lock;
        int t = stoi(target);
        for (const string &s : deadends)
            lock.insert(stoi(s));

        if (lock.count(0))
            return -1;
        if (0 == t)
            return 0;
        int res = 0;
        vector<bool> vis(10000, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            ++res;
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto cur = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int tmp = cur;
                    int pk = pow(10, k);
                    int kth = (tmp / pk) % 10;
                    tmp = tmp - kth * pk;
                    int l = kth - 1;
                    int r = kth + 1;
                    if (kth == 0)
                        l = 9;
                    else if (kth == 9)
                        r = 0;
                    l = tmp + l * pk;
                    r = tmp + r * pk;

                    if (l == t || r == t)
                        return res;
                    if (!lock.count(l) && !vis[l])
                    {
                        vis[l] = true;
                        q.push(l);
                    }
                    if (!lock.count(r) && !vis[r])
                    {
                        vis[r] = true;
                        q.push(r);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

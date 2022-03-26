/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1)
        {
            int cur1 = q.top();
            q.pop();
            int cur2 = q.top();
            q.pop();
            if (cur1 < cur2)
                swap(cur1, cur2);
            if (cur1 != cur2)
                q.push(cur1 - cur2);
        }
        if (q.empty())
            return 0;
        return q.top();
    }
};
// @lc code=end

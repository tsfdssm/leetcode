/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = speed.size();
        vector<pair<int, int>> all;
        for (int i = 0; i < n; ++i)
        {
            all.emplace_back(position[i], speed[i]);
        }
        sort(all.begin(), all.end());
        stack<double> stk;
        for (int i = 0; i < n; ++i)
        {
            double cur = ((double)target - all[i].first) / all[i].second;
            while (!stk.empty() && stk.top() <= cur)
                stk.pop();
            stk.push(cur);
        }
        return stk.size();
    }
};
// @lc code=end

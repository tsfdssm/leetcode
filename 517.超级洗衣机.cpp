/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (total % n != 0)
            return -1;
        int fi = total / n;
        int res = 0;
        int maxN = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            machines[i] -= fi;
        for (int i = 0; i < n; ++i)
        {
            maxN = max(maxN, machines[i]);
            sum += machines[i];
            res = max(res, max(maxN, abs(sum)));
        }
        return res;
    }
};
// @lc code=end

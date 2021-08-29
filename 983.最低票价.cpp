/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int lens[3] = {1, 7, 30};
        int n = days.size();
        const int inf = 0x3f3f3f3f;
        vector<int> memo(n, inf);
        function<int(int)> dp = [&](int i) {
            if (i >= n)
                return 0;
            if (memo[i] != inf)
                return memo[i];
            for (int k = 0; k < 3; ++k)
            {
                int j = i + 1;
                for (; j < n; ++j)
                {
                    if (days[i] + lens[k] <= days[j])
                        break;
                }
                memo[i] = min(memo[i], dp(j) + costs[k]);
            }
            return memo[i];
        };
        return dp(0);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size();
        int n = heaters.size();
        int res = 0;
        int k = 0;
        for (int i = 0; i < m; ++i)
        {
            int r = INT_MAX;
            for (int j = k; j < n; ++j)
            {
                k = houses[i] >= heaters[j] ? j : k;
                r = min(r, abs(houses[i] - heaters[j]));
                if (houses[i] < heaters[j])
                    break;
            }
            res = max(res, r);
        }
        return res;
    }
};
// @lc code=end

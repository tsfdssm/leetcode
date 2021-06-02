/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> path(n, -1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (0 == nums[i] % nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                }
            }
        }
        vector<int> res;
        int ed = (max_element(dp.begin(), dp.end()) - dp.begin()); // / sizeof(int);
        while (ed != -1)
        {
            res.push_back(nums[ed]);
            ed = path[ed];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

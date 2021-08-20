/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (1 == nums[i])
                pos.emplace_back(i);
        if (pos.size() < goal)
            return 0;

        int k = pos.size();
        int res = 0;
        if (0 == goal)
        {

            if (0 == pos.size())
                res = n * (n + 1) / 2;
            else
            {
                res += pos[0] * (pos[0] + 1) / 2;
                pos.emplace_back(n);
                for (int i = 1; i < pos.size(); ++i)
                {
                    res += (pos[i] - pos[i - 1] - 1) * (pos[i] - pos[i - 1]) / 2;
                }
            }
        }
        else
            for (int i = goal; i <= k; ++i)
            {
                int left = i == goal ? pos[0] + 1 : pos[i - goal] - pos[i - goal - 1];
                int right = i < k ? pos[i] - pos[i - 1] : n - pos[k - 1];
                res += left * right;
            }
        return res;
    }
};
// @lc code=end

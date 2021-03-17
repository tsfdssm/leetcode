/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int k = j + 1, t = n - 1;
                while (k < t)
                {
                    while (k < t && k > j + 1 && nums[k - 1] == nums[k])
                        k++;

                    while (k < t && t < n - 1 && nums[t + 1] == nums[t])
                        t--;
                    if (k == t)
                        break;
                    int sum = nums[i] + nums[j] + nums[k] + nums[t];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[t]});
                        k++;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        t--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

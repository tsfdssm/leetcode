/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int min = 1000000;
        int res = 0;

        auto update = [&](int cur) {
            if (min > abs(cur - target))
            {
                min = abs(cur - target);
                res = cur;
            }
        };

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int t = nums.size() - 1;
            int j = i + 1;
            while (j < t)
            {
                int sum = nums[i] + nums[j] + nums[t];
                if (sum == target)
                    return sum;
                // int def = abs(sum - target);
                // if (def < min)
                // {
                //     min = def;
                //     res = sum;
                // }
                update(sum);
                if (sum > target)
                {
                    t--;
                    while (j < t && nums[t] == nums[t + 1])
                        --t;
                }
                else
                {
                    ++j;
                    while (j < t && nums[j - 1] == nums[j])
                        ++j;
                }
            }
        }
        return res;
    }
};
// @lc code=end

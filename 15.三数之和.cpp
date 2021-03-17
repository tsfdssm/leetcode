/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size();i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int t = nums.size() - 1;
        int target = -nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            while (j < t && nums[j] + nums[t] > target)
                t--;
            if (j == t)
                break;
            if (nums[j] + nums[t] == target)
                res.push_back(vector<int>{nums[i], nums[j], nums[t]});
        }
       
    }
     return res;
}
};
// @lc code=end


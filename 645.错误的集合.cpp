/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int rep = -1;
        int los = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == (i + 1))
                continue;
            if (nums[nums[i] - 1] == nums[i])
                rep = nums[i];
            else
            {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
            {
                los = i + 1;
                break;
            }
        return {rep, los};
    }
};
// @lc code=end

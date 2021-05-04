/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        for (const auto &num : nums)
            hash[num]++;

        for (const auto &n : hash)
            if (n.second > (nums.size() / 2))
                return n.first;
        return -1;
    }
};
// @lc code=end

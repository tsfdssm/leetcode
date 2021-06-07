/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            auto it = mp.find(num);
            if (it == mp.end())
            {
                mp.insert(make_pair(num, vector<int>(1, i)));
            }
            else
            {
                it->second.push_back(i);
            }
        }
    }

    int pick(int target)
    {
        auto &vec = mp.find(target)->second;
        return vec[random() % vec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

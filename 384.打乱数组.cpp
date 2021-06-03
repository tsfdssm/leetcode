/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> backup;
    vector<int> now;
    Solution(vector<int> &nums)
    {
        backup.assign(nums.begin(), nums.end());
        now.assign(nums.begin(), nums.end());
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return backup;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int n = now.size();
        for (int i = 0; i < n; ++i)
        {
            swap(now[i], now[random() % n]);
        }
        return now;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

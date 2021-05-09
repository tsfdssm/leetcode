/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (0 == nums.size())
            return {};
        int n = nums.size();

        deque<int> q;
        for (int i = 0; i < k; ++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }

        vector<int> res = {nums[q.front()]};

        for (int i = k; i < n; ++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);
            while (q.front() <= i - k)
            {
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
        return res;
        //std::move();
    }
};
// @lc code=end

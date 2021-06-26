/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution
{
public:
    int sum = 0;

    vector<int> psum;
    Solution(vector<int> &w)
    {
        int n = w.size();
        psum.resize(n);
        psum[0] = w[0];
        for (int i = 1; i < n; ++i)
        {
            psum[i] = psum[i - 1] + w[i];
        }
        sum = psum[n - 1];
    }

    int pickIndex()
    {
        int target = random() % sum;
        int l = 0, r = psum.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (psum[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

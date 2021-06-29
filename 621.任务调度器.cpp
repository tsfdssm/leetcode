/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int len = tasks.size();
        vector<int> vec(26, 0);
        for (char c : tasks)
            vec[c - 'A']++;
        int maxn = *max_element(vec.begin(), vec.end());
        int cnt = 0;
        for (int num : vec)
            if (num == maxn)
                ++cnt;
        return max((maxn - 1) * (n + 1) + cnt, len);
    }
};
// @lc code=end

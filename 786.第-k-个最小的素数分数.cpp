/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();

        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> minHeap;

        for (int j = 1; j < n; ++j)
            minHeap.push({(double)arr[0] / arr[j], 0, j});
        while (k > 1)
        {
            auto [val, i, j] = minHeap.top();
            minHeap.pop();
            --k;
            if (i + 1 < j)
                minHeap.push({(double)arr[i + 1] / arr[j], i + 1, j});
        }
        auto [val, i, j] = minHeap.top();
        return {arr[i], arr[j]};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int maxn = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > maxn)
                maxn = arr[i];
            if (i == maxn)
                ++res;
        }
        return res;
    }
};
// @lc code=end

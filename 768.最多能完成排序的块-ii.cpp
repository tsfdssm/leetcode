/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pre(n), nxt(n);
        for (int i = 0; i < n; ++i)
        {
            if (0 == i)
                pre[i] = arr[i];
            else
                pre[i] = max(pre[i - 1], arr[i]);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (i == n - 1)
                nxt[i] = arr[i];
            else
                nxt[i] = min(nxt[i + 1], arr[i]);
        }

        int res = 1;
        for (int i = 0; i < n - 1; ++i)
            if (pre[i] <= nxt[i + 1])
                ++res;
        return res;
    }
};
// @lc code=end

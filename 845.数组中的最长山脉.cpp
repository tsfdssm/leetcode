/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int idx = 0;
        int res = 0;

        while (idx < n)
        {
            while (idx < n - 1 && arr[idx] >= arr[idx + 1])
                ++idx;
            int j = idx;
            while (j < n - 1 && arr[j] < arr[j + 1])
                ++j;
            if (j == n - 1)
                break;
            if (arr[j + 1] == arr[j])
            {
                idx = j + 1;
                continue;
            }
            int k = j;
            while (k < n - 1 && arr[k] > arr[k + 1])
                ++k;
            res = max(res, k - idx + 1);
            idx = k;
        }
        return res;
    }
};
// @lc code=end

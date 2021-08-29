/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();
        int cur = n;
        vector<int> res;
        for (; cur > 1; --cur)
        {
            if (arr[cur - 1] == cur)
                continue;
            int i = 0;
            for (; i < n; ++i)
            {
                if (arr[i] == cur)
                    break;
            }
            res.emplace_back(i + 1);
            res.emplace_back(cur);
            reverse(arr.begin(), arr.begin() + i + 1);
            reverse(arr.begin(), arr.begin() + cur);
        }
        return res;
    }
};
// @lc code=end

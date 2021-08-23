/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        //if (n < 3)
        //return false;
        int idx = 0;
        for (; idx < n - 1; ++idx)
        {
            if (arr[idx] < arr[idx + 1])
                continue;
            else if (arr[idx] == arr[idx + 1])
                return false;
            else
                break;
        }
        if (idx == 0 || idx == n - 1)
            return false;
        for (; idx < n - 1; ++idx)
        {
            if (arr[idx] > arr[idx + 1])
                continue;
            else if (arr[idx] <= arr[idx + 1])
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (0 != sum % 3)
            return false;
        int k = sum / 3;
        int cur = 0;
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cur += arr[i];
            if (cur == k)
            {
                cur = 0;
                ++cnt;
            }
        }
        return cnt >= 3;
    }
};
// @lc code=end

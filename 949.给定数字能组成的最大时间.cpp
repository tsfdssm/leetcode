/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */

// @lc code=start
class Solution
{
public:
    string largestTimeFromDigits(vector<int> &arr)
    {
        string res = "";
        int hour = -1;
        int min = -1;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                if (i == j)
                    continue;
                int curh = arr[i] * 10 + arr[j];
                if (curh >= 24 || curh < hour)
                    continue;
                for (int k = 0; k < 4; ++k)
                {
                    if (i == k || j == k)
                        continue;
                    int l = 6 - i - j - k;
                    int curm = arr[k] * 10 + arr[l];
                    if (curm >= 60)
                        continue;
                    if (curh > hour || (curh == hour && curm > min))
                    {
                        hour = curh;
                        min = curm;
                        res = to_string(arr[i]) + to_string(arr[j]) + ":" + to_string(arr[k]) + to_string(arr[l]);
                    }
                }
            }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        int res = 1;
        int tmp = 1;
        int flag = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] < arr[i + 1])
            {
                if (0 >= flag)
                {
                    tmp = 2;
                }
                else
                {
                    tmp++;
                }
                flag = -1;
            }
            else if (arr[i] > arr[i + 1])
            {
                if (0 <= flag)
                {
                    tmp = 2;
                }
                else
                {
                    tmp++;
                }
                flag = 1;
            }
            else
            {
                flag = 0;
                tmp = 1;
            }
            res = max(res, tmp);
        }
        return res;
    }
};
// @lc code=end

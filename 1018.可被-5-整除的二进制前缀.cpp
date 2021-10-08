/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> res(n, false);
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            cur *= 2;
            cur += nums[i];
            if (cur % 5 == 0)
                res[i] = true;
            cur %= 5;
        }
        return res;
        /*int prepre = 0;
        int pre = nums[0];
        vector<bool> res(n);
        res[0] = (nums[0]==0);
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == 0)
                res[i] = res[i - 1];
            else
            {
                if ((prepre == 1) && (pre == 0))
                    res[i] = true;
                else
                    res[i] = false;
            }
            prepre = pre;
            pre = nums[i];
        }
        return res;*/
    }
};
// @lc code=end
